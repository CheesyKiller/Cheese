module;

#include <string>
#include <vector>
#include <functional>
#include <memory>

export module WindowManager;

export import WindowContext;

export struct WindowManager {
    std::vector<std::shared_ptr<WindowContext::Window>> windows;
    std::vector<std::function<void()>> perFrameCodes;

    static WindowManager* getInstance();

    ~WindowManager();

    void createWindow(const std::string& windowName, std::function<void()> initialCode,
        std::function<void()> perFrameCode, int width = 800, int height = 600,
        const std::string& parentWindowName = "");

    void limitFrameRate(const std::string& windowName, unsigned int targetFPS);
    int getRefreshRate(const std::string& windowName);
    void vSync(const std::string& windowName);

    void run();
    void close();

    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

private:
    WindowManager() = default;
};