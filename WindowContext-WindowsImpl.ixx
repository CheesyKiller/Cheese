module;

#include <functional>
#include <stdexcept>
#include <Windows.h>
#include <chrono>
#include <thread>

export module WindowContext:WindowsImpl;
export import :Base;
export import GLAD;

namespace WindowContext {

    LRESULT CALLBACK CustomWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
        case WM_SIZE: {
            int width = LOWORD(lParam);
            int height = HIWORD(lParam);

            auto callback = reinterpret_cast<std::function<void(int, int)>*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
            if (callback && *callback) {
                (*callback)(width, height);
            }

            // Redraw the window during resizing
            InvalidateRect(hwnd, nullptr, TRUE);
            return 0;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    struct Window::Impl {
        HWND hwnd;       // Window handle for Windows
        HDC hdc;         // Device context for OpenGL
        HGLRC hglrc;     // OpenGL rendering context
        std::function<void(int, int)> framebufferSizeCallback;

        Impl(int width, int height, std::string_view title, Impl* sharedImpl = nullptr) {
            // Step 1: Register window class
            WNDCLASS wc = { 0 };
            wc.lpfnWndProc = CustomWndProc;
            wc.hInstance = GetModuleHandle(nullptr);
            wc.lpszClassName = L"ContextHandlerWindowClass";
            RegisterClass(&wc);

            // Step 2: Create the window
            hwnd = CreateWindowEx(
                0,
                L"ContextHandlerWindowClass",
                std::wstring(title.begin(), title.end()).c_str(),
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                nullptr, nullptr, wc.hInstance, nullptr
            );

            // Handle Resize events
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&framebufferSizeCallback));

            // Step 3: Set up pixel format for OpenGL
            hdc = GetDC(hwnd);
            PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1 };
            pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
            pfd.iPixelType = PFD_TYPE_RGBA;
            pfd.cColorBits = 32;
            int pixelFormat = ChoosePixelFormat(hdc, &pfd);
            if (pixelFormat == 0) {
                error("Failed to choose pixel format for Window " + (std::string)title);
            }
            if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
				error("Failed to set pixel format for Window " + (std::string)title);
            }

            // Step 4: Create OpenGL context
            hglrc = wglCreateContext(hdc);
            if (!hglrc) {
				error("Failed to create OpenGL context for Window " + (std::string)title);
            }

            // Step 5: Share lists if a shared context is provided
            if (sharedImpl) {
                if (!wglShareLists(sharedImpl->hglrc, hglrc)) {
                    wglDeleteContext(hglrc);
					error("Failed to share OpenGL contexts");
                }
            }

            // Step 6: Make the context current
            if (!wglMakeCurrent(hdc, hglrc)) {
                wglDeleteContext(hglrc);
				error("Failed to make OpenGL context current");
            }

            // Step 7: Load OpenGL functions via GLAD
            if (!GLAD::gladLoadGLLoader((GLAD::GLADloadproc)wglGetProcAddress)) {
                wglMakeCurrent(nullptr, nullptr);
                wglDeleteContext(hglrc);
				error("Failed to initialize GLAD");
            }
        }

        ~Impl() {
            if (hglrc) {
                wglMakeCurrent(nullptr, nullptr);
                wglDeleteContext(hglrc);
            }
            if (hwnd && hdc) {
                ReleaseDC(hwnd, hdc);
                DestroyWindow(hwnd);
            }
        }
    };

    Window::Window(std::string title, int width, int height, Window* sharedWindow)
        : impl(new Impl(width, height, title, sharedWindow ? sharedWindow->impl : nullptr)) {}

    Window::~Window() {
        delete impl;
    }

    void Window::SwapBuffers() {
        if (!shouldClose) {
            ::SwapBuffers(impl->hdc);

            if (targetFPS != 0) {
                static auto lastTime = std::chrono::high_resolution_clock::now();
                auto currentTime = std::chrono::high_resolution_clock::now();

                // Calculate the frame duration in microseconds
                const int frameDurationMicroseconds = 1000000 / targetFPS;

                // Measure the elapsed time since the last frame
                auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - lastTime).count();

                // If the frame finished early, wait
                if (elapsed < frameDurationMicroseconds) {
                    std::this_thread::sleep_for(std::chrono::microseconds(frameDurationMicroseconds - elapsed));
                }

                // Update the last frame time
                lastTime = std::chrono::high_resolution_clock::now();
            }
        }
    }

    void Window::Close() {
		shouldClose = true;
    }

    bool Window::ShouldClose() {
		if (shouldClose) {
			return true;
		}

        MSG msg;
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                return true;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return false;
    }

    void Window::SetTitle(std::string title) {
        SetWindowText(impl->hwnd, std::wstring(title.begin(), title.end()).c_str());
    }

    std::string Window::GetTitle() const {
		int length = GetWindowTextLength(impl->hwnd);
		std::wstring buffer(length, L'\0');
		GetWindowText(impl->hwnd, buffer.data(), length + 1);
		return std::string(buffer.begin(), buffer.end());
    }

    void Window::PollEvents() {
        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	void Window::MakeCurrent() {
		wglMakeCurrent(impl->hdc, impl->hglrc);
	}

	void Window::Show() {
		ShowWindow(impl->hwnd, SW_SHOW);
	}

	void Window::Hide() {
		ShowWindow(impl->hwnd, SW_HIDE);
	}

	int Window::GetMonitorRefreshRate() {
		DEVMODE devMode;
		EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &devMode);
		return devMode.dmDisplayFrequency;
	}

    void Window::VSync() {
		targetFPS = GetMonitorRefreshRate();
    }

    void Window::SetFramebufferSizeCallback(std::function<void(int, int)> callback) {
        impl->framebufferSizeCallback = [callback](int width, int height) {
            // Update the OpenGL viewport
            GLAD::glViewport(0, 0, width, height);

            // Call the user-provided callback, if any
            if (callback) {
                callback(width, height);
            }
            };
    }
}