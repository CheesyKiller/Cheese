module;

#include <Windows.h>
#include <chrono>

export module WindowContext:WindowsImpl;

import GLM;
import std.core;
import GLAD;
import :Base;
import WindowContextCamera;
import DebugLogger;

export namespace WindowContext {

    LRESULT CALLBACK CustomWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    struct Impl {
        HWND hwnd;
        HDC hdc;
        HGLRC hglrc; 
        std::function<void(int, int)> framebufferSizeCallback;

        bool cursorCaptured = false;
        POINT centerPos = { 0, 0 };
        int deltaX = 0;
        int deltaY = 0;

        Impl(int width, int height, std::string_view title, Impl* sharedImpl = nullptr) {
            WNDCLASS wc = { 0 };
            wc.lpfnWndProc = CustomWndProc;
            wc.hInstance = GetModuleHandle(nullptr);
            wc.lpszClassName = L"ContextHandlerWindowClass";
            RegisterClass(&wc);

            hwnd = CreateWindowEx(
                0,
                L"ContextHandlerWindowClass",
                std::wstring(title.begin(), title.end()).c_str(),
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                nullptr, nullptr, wc.hInstance, this
            );

            if (!hwnd) {
                error("Failed to create window.");
            }

            hdc = GetDC(hwnd);
            PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1 };
            pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
            pfd.iPixelType = PFD_TYPE_RGBA;
            pfd.cColorBits = 32;
            int pixelFormat = ChoosePixelFormat(hdc, &pfd);
            if (pixelFormat == 0) {
                error("Failed to choose pixel format for Window " + std::string(title));
            }
            if (!SetPixelFormat(hdc, pixelFormat, &pfd)) {
                error("Failed to set pixel format for Window " + std::string(title));
            }

            hglrc = wglCreateContext(hdc);
            if (!hglrc) {
                error("Failed to create OpenGL context for Window " + std::string(title));
            }

            if (sharedImpl) {
                if (!wglShareLists(sharedImpl->hglrc, hglrc)) {
                    wglDeleteContext(hglrc);
                    error("Failed to share OpenGL contexts");
                }
            }

            if (!wglMakeCurrent(hdc, hglrc)) {
                wglDeleteContext(hglrc);
                error("Failed to make OpenGL context current");
            }

            if (!GLAD::gladLoadGLLoader((GLAD::GLADloadproc)wglGetProcAddress)) {
                wglMakeCurrent(nullptr, nullptr);
                wglDeleteContext(hglrc);
                error("Failed to initialize GLAD");
            }

            SetForegroundWindow(hwnd);
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

        void EnableCursorCapture(bool enable) {
            if (enable && !cursorCaptured) {
                ShowCursor(FALSE);

                RECT rect;
                GetClientRect(hwnd, &rect);
                centerPos.x = (rect.left + rect.right) / 2;
                centerPos.y = (rect.top + rect.bottom) / 2;

                POINT centerScreen = { centerPos.x, centerPos.y };
                ClientToScreen(hwnd, &centerScreen);

                SetCursorPos(centerScreen.x, centerScreen.y);

                // Note: windows will just decide to stop refreshing for some reason if it's not in the foreground upon switching
                if (GetForegroundWindow() != hwnd) {
                    SetForegroundWindow(hwnd);
                }
            }
            if (!enable && cursorCaptured) {
                ShowCursor(TRUE);
            }
            cursorCaptured = enable;
        }

        std::pair<int, int> GetMouseDeltas() {
            auto deltas = std::make_pair(deltaX, deltaY);
            deltaX = 0;
            deltaY = 0;
            return deltas;
        }

        void CenterCursor() {
            RECT rect;
            GetClientRect(hwnd, &rect);
            centerPos.x = (rect.left + rect.right) / 2;
            centerPos.y = (rect.top + rect.bottom) / 2;

            POINT centerScreen = { centerPos.x, centerPos.y };
            ClientToScreen(hwnd, &centerScreen);
            SetCursorPos(centerScreen.x, centerScreen.y);
        }
    };

    LRESULT CALLBACK CustomWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        Impl* impl = reinterpret_cast<Impl*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        if (!impl && uMsg == WM_NCCREATE) {
            CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
            impl = static_cast<Impl*>(cs->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(impl));
        }

        if (impl) {
            switch (uMsg) {
            case WM_SIZE:
                if (impl->framebufferSizeCallback) {
                    int width = LOWORD(lParam);
                    int height = HIWORD(lParam);
                    impl->framebufferSizeCallback(width, height);
                }
                InvalidateRect(hwnd, nullptr, TRUE);
                return 0;

            case WM_MOUSEMOVE: {
                if (impl->cursorCaptured) {
                    POINT currentPos;
                    GetCursorPos(&currentPos);
                    ScreenToClient(hwnd, &currentPos);

                    int offsetX = currentPos.x - impl->centerPos.x;
                    int offsetY = currentPos.y - impl->centerPos.y;

                    if (offsetX != 0 || offsetY != 0) {
                        impl->deltaX += offsetX;
                        impl->deltaY += offsetY;

                        if (abs(offsetX) > 5 || abs(offsetY) > 5) {
                            impl->CenterCursor();
                        }
                    }

                    return 0;
                }
                break;
            }

            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;

            default:
                break;
            }
        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    Window::Window(std::string title, int width, int height, Window* sharedWindow)
        : impl(new Impl(width, height, title, sharedWindow ? sharedWindow->impl : nullptr)),
        camera(std::make_shared<Camera>(
            glm::vec3(0.0f, 0.0f, 5.0f), // Position
            glm::vec3(0.0f, 1.0f, 0.0f), // Up vector
            -90.0f,                      // Yaw
            0.0f                         // Pitch
        )) {}

    Window::~Window() {
        delete impl;
    }

    void Window::SwapBuffers() {
        if (!shouldClose) {
            ::SwapBuffers(impl->hdc);
        }
    }

    void Window::Close() {
        shouldClose = true;
    }

    bool Window::ShouldClose() {
        return shouldClose;
    }

    bool Window::checkIfActive() {
        return GetForegroundWindow() == impl->hwnd;
    }

    void Window::SetTitle(std::string title) {
        int wideSize = MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, nullptr, 0);
        std::wstring wideTitle(wideSize, L'\0');
        MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, &wideTitle[0], wideSize);

        SetWindowTextW(impl->hwnd, wideTitle.c_str());
    }

    std::string Window::GetTitle() const {
        int length = GetWindowTextLength(impl->hwnd);
        std::wstring buffer(length + 1, L'\0');
        GetWindowTextW(impl->hwnd, &buffer[0], length + 1);
        buffer.resize(length);
        std::string narrowTitle(buffer.begin(), buffer.end());
        return narrowTitle;
    }

    void Window::SetCursorVisible(bool visible) {
        if (visible) {
            impl->EnableCursorCapture(false);
        }
        else {
            impl->EnableCursorCapture(true);
        }
    }

    void Window::PollEvents() {
        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT) {
                shouldClose = true;
            }
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

    void Window::EnableVSync(bool enable) {
        if (GLAD::wglSwapIntervalEXT) {
            GLAD::wglSwapIntervalEXT(enable ? 1 : 0);
        }
    }

    void Window::SetFramebufferSizeCallback(std::function<void(int, int)> callback) {
        impl->framebufferSizeCallback = std::move(callback);
    }

    void Window::ResizeViewport(int width, int height) {
        GLAD::glViewport(0, 0, width, height);
    }

    void Window::EnableCursorCapture(bool enable) {
        impl->EnableCursorCapture(enable);
    }

	void Window::ToggleCursorCapture() {
		impl->EnableCursorCapture(!impl->cursorCaptured);
	}

    std::pair<int, int> Window::GetMouseDeltas() {
        if (impl) {
            return impl->GetMouseDeltas();
        }
        return { 0, 0 };
    }
}