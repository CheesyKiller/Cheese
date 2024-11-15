module;

#include <string>
#include <vector>
#include <functional>
#include <iostream>

export module WindowManager;

export import WindowContext;

export struct WindowManager {
    std::vector<std::shared_ptr<WindowContext::Window>> windows = std::vector<std::shared_ptr<WindowContext::Window>>();
    std::vector<std::function<void()>> perFrameCodes = std::vector<std::function<void()>>();

	WindowManager() = default;
    ~WindowManager() {
		windows.clear();
		perFrameCodes.clear();
    }

    void createWindow(std::string windowName, std::function<void()> initialCode, std::function<void()> perFrameCode) {
		createWindow(windowName, initialCode, perFrameCode, 800, 600);
    }

    void createWindow(std::string windowName, std::function<void()> initialCode, std::function<void()> perFrameCode, std::string parentWindowName) {
        createWindow(windowName, initialCode, perFrameCode, 800, 600, parentWindowName);
    }

    // Create a window and store the associated per-frame code callback
    void createWindow(std::string windowName, std::function<void()> initialCode, std::function<void()> perFrameCode, int width, int height, std::string parentWindowName = "") {
		if (parentWindowName != "" && windows.size() > 0) {
			WindowContext::Window* parentWindow = nullptr;
			for (int i = 0; i < windows.size(); ++i) {
				if (windows[i]->GetTitle() == parentWindowName) {
                    parentWindow = windows[i].get();
					break;
				}
			}
            if (parentWindow != nullptr) {
                windows.push_back(std::make_shared<WindowContext::Window>(windowName, width, height, parentWindow));
            }
            else {
				std::cerr << "Parent window (" << parentWindowName << "!=" << windows[0]->GetTitle() << ") for " << windowName << std::endl;
				std::terminate();
            }
        }
        else {
            windows.push_back(std::make_shared<WindowContext::Window>(windowName, width, height));
        }
        
        perFrameCodes.push_back(std::move(perFrameCode));

		windows[windows.size() - 1]->MakeCurrent();

		if (windowName[0] == '_') {
            windows[windows.size() - 1]->Hide();
		}

		initialCode();

		std::cout << "Created window: " << windowName << std::endl;
    }

    // Main run loop to handle all windows
    void run() {
        while (true) {
            bool allClosed = true;
            for (size_t i = 0; i < windows.size(); ++i) {
                if (!windows[i]->ShouldClose()) {
                    windows[i]->MakeCurrent();

                    allClosed = false;
                    windows[i]->PollEvents();

                    // Execute the per-frame callback for this window
                    perFrameCodes[i]();

                    // Swap buffers for rendering
                    windows[i]->SwapBuffers();
                }
            }
            // Exit loop if all windows are closed
            if (allClosed) break;
        }
    }
};