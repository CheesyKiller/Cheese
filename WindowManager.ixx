export module WindowManager;

import std.core;
import WindowContext;

export struct WindowManager {
    std::vector<std::shared_ptr<WindowContext::Window>> windows;
    std::vector<std::function<void()>> perFrameCodes;
    bool centerMouse = true;

    static WindowManager* getInstance();

    ~WindowManager();

    void createWindow(const std::string& windowName, std::function<void()> initialCode,
        std::function<void()> perFrameCode, int width = 800, int height = 600,
        const std::string& parentWindowName = "");

    void limitFrameRate(const std::string& windowName, unsigned int targetFPS);
    int getRefreshRate(const std::string& windowName);
    void setVSync(const std::string& windowName, const bool& state);

    void run();
    void close();

    std::shared_ptr<WindowContext::Camera> getWindowCamera(const std::string& windowName);
    bool checkForActiveWindow();

    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;
private:
    WindowManager();
};