module;

#include <Windows.h>
#include <chrono>

export module WindowContext:WindowsImpl;
export import :Base;
export import GLAD;
export import WindowContextCamera;

import std.core;

export namespace WindowContext {

    LRESULT CALLBACK CustomWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    struct Impl {
        HWND hwnd;       // Window handle for Windows
        HDC hdc;         // Device context for OpenGL
        HGLRC hglrc;     // OpenGL rendering context
        std::function<void(int, int)> framebufferSizeCallback;

        // Members for cursor capture and mouse delta calculation
        bool cursorCaptured = false;
        POINT centerPos = { 0, 0 };
        int deltaX = 0;
        int deltaY = 0;

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
                nullptr, nullptr, wc.hInstance, this
            );

            if (!hwnd) {
                error("Failed to create window.");
            }

            // Handle Resize events
            // SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&framebufferSizeCallback));
            // The GWLP_USERDATA is set in the window procedure on WM_NCCREATE

            // Step 3: Set up pixel format for OpenGL
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

            // Step 4: Create OpenGL context
            hglrc = wglCreateContext(hdc);
            if (!hglrc) {
                error("Failed to create OpenGL context for Window " + std::string(title));
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

        // Method to enable or disable cursor capture
        void EnableCursorCapture(bool enable) {
            if (enable && !cursorCaptured) {
                // Hide the cursor
                ShowCursor(FALSE);

                // Get the client area center
                RECT rect;
                GetClientRect(hwnd, &rect);
                centerPos.x = (rect.left + rect.right) / 2;
                centerPos.y = (rect.top + rect.bottom) / 2;

                // Convert client coordinates to screen coordinates
                POINT centerScreen = { centerPos.x, centerPos.y };
                ClientToScreen(hwnd, &centerScreen);

                // Reposition the cursor to the center
                SetCursorPos(centerScreen.x, centerScreen.y);

                cursorCaptured = true;
            }
            else if (!enable && cursorCaptured) {
                // Show the cursor
                ShowCursor(TRUE);
                cursorCaptured = false;
            }
        }

        // Method to retrieve and reset mouse deltas
        std::pair<int, int> GetMouseDeltas() {
            auto deltas = std::make_pair(deltaX, deltaY);
            deltaX = 0;
            deltaY = 0;
            return deltas;
        }

        // Method to center the cursor
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
                    // Current cursor position
                    POINT currentPos;
                    GetCursorPos(&currentPos);
                    ScreenToClient(hwnd, &currentPos);

                    // Calculate delta from center
                    int deltaX = currentPos.x - impl->centerPos.x;
                    int deltaY = currentPos.y - impl->centerPos.y;

                    // Accumulate deltas
                    impl->deltaX += deltaX;
                    impl->deltaY += deltaY;

                    // Re-center the cursor
                    impl->CenterCursor();

                    return 0; // We've handled the message
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

    void Window::SetTitle(std::string title) {
        // Convert std::string (UTF-8) to std::wstring (UTF-16)
        int wideSize = MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, nullptr, 0);
        std::wstring wideTitle(wideSize, L'\0');
        MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, &wideTitle[0], wideSize);

        // Set the window title
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

    // Implementations for cursor capture and mouse delta handling

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