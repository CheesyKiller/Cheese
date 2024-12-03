export module WindowContext:Base;

import std.core;

export namespace WindowContext {
    struct Camera;
    struct Impl;

    // Window interface class
    struct Window {
        Window(std::string title, int width = 800, int height = 600, Window* sharedWindow = nullptr);
        ~Window();

        void SwapBuffers();

        void Close();
        bool ShouldClose();

        void SetTitle(std::string title);
        std::string GetTitle() const;

        void PollEvents();

        void MakeCurrent();

        void Show();
        void Hide();

        int GetMonitorRefreshRate();
        void EnableVSync(bool enable);

        void SetFramebufferSizeCallback(std::function<void(int, int)> callback);
        void ResizeViewport(int width, int height);

        void EnableCursorCapture(bool enable);
        void ToggleCursorCapture();
        void SetCursorVisible(bool visible);
        std::pair<int, int> GetMouseDeltas();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        unsigned int targetFPS;

        std::shared_ptr<Camera> camera;

    private:
        bool shouldClose = false;

        Impl* impl;
    };
}