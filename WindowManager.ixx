module;

#include <string>
#include <vector>
#include <functional>
#include <iostream>

export module WindowManager;

export import WindowContext;

export struct WindowManager {
    std::vector<std::shared_ptr<WindowContext::Window>> windows;
    std::vector<std::function<void()>> perFrameCodes;

    static WindowManager* getInstance() {
        static WindowManager instance;
        return &instance;
    }

    ~WindowManager() {
        close(); // Clean up all windows
    }

    void createWindow(const std::string& windowName, std::function<void()> initialCode,
        std::function<void()> perFrameCode, int width = 800, int height = 600,
        const std::string& parentWindowName = "")
    {
        // Find parent window if specified
        WindowContext::Window* parentWindow = nullptr;
        if (!parentWindowName.empty()) {
            auto it = std::find_if(windows.begin(), windows.end(),
                [&](const std::shared_ptr<WindowContext::Window>& window) {
                    return window->GetTitle() == parentWindowName;
                });

            if (it != windows.end()) {
                parentWindow = it->get();
            }
            else {
				error("Parent window (" + parentWindowName + ") not found for " + windowName);
            }
        }

        // Create the window
        if (parentWindow) {
            windows.push_back(std::make_shared<WindowContext::Window>(windowName, width, height, parentWindow));
        }
        else {
            windows.push_back(std::make_shared<WindowContext::Window>(windowName, width, height));
        }

        // Register per-frame callback
        perFrameCodes.push_back(std::move(perFrameCode));

        // Initialize the window
        auto& newWindow = windows.back();
        newWindow->MakeCurrent();
        if (!windowName.empty() && windowName[0] == '_') {
            newWindow->Hide();
        }
        initialCode();

#ifdef _DEBUG
        std::cout << "Created window: " << windowName << std::endl;
#endif
    }

    void run() {
        while (true) {
            bool allClosed = true;
            for (size_t i = 0; i < windows.size(); ++i) {
                auto& window = windows[i];
                if (!window->ShouldClose()) {
                    window->MakeCurrent();
                    allClosed = false;
                    window->PollEvents();
                    perFrameCodes[i]();
                    window->SwapBuffers();
                }
            }
            if (allClosed) break; // Exit loop if all windows are closed
        }
    }

    void close() {
        for (auto& window : windows) {
            window->Close();
        }
        windows.clear(); // Release resources
        perFrameCodes.clear();
    }

    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

private:
    WindowManager() = default;
};