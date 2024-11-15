module;


#include <stdexcept>

export module WindowContext:WindowsImpl;
export import :Base;
export import GLAD;

#include <Windows.h>

namespace WindowContext {

    struct Window::Impl {
        HWND hwnd;       // Window handle for Windows
        HDC hdc;         // Device context for OpenGL
        HGLRC hglrc;     // OpenGL rendering context

        Impl(int width, int height, std::string_view title, Impl* sharedImpl = nullptr) {
            // Step 1: Register window class
            WNDCLASS wc = { 0 };
            wc.lpfnWndProc = DefWindowProc;
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

            // Step 3: Set up pixel format for OpenGL
            hdc = GetDC(hwnd);
            PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1 };
            pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
            pfd.iPixelType = PFD_TYPE_RGBA;
            pfd.cColorBits = 32;
            int pixelFormat = ChoosePixelFormat(hdc, &pfd);
            if (pixelFormat == 0) {
                throw std::runtime_error("Failed to choose pixel format");
            }
            if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
                throw std::runtime_error("Failed to set pixel format");
            }

            // Step 4: Create OpenGL context
            hglrc = wglCreateContext(hdc);
            if (!hglrc) {
                throw std::runtime_error("Failed to create OpenGL context");
            }

            // Step 5: Share lists if a shared context is provided
            if (sharedImpl) {
                if (!wglShareLists(sharedImpl->hglrc, hglrc)) {
                    wglDeleteContext(hglrc);
                    throw std::runtime_error("Failed to share OpenGL contexts");
                }
            }

            // Step 6: Make the context current
            if (!wglMakeCurrent(hdc, hglrc)) {
                wglDeleteContext(hglrc);
                throw std::runtime_error("Failed to make OpenGL context current");
            }

            // Step 7: Load OpenGL functions via GLAD
            if (!gladLoadGLLoader((GLADloadproc)wglGetProcAddress)) {
                wglMakeCurrent(nullptr, nullptr);
                wglDeleteContext(hglrc);
                throw std::runtime_error("Failed to initialize GLAD");
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
        ::SwapBuffers(impl->hdc);
    }

    bool Window::ShouldClose() {
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
}