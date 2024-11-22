#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <iostream>

import WindowManager;

WindowManager* WindowManager::getInstance() {
    static WindowManager instance;
    return &instance;
}

WindowManager::~WindowManager() {
    close();
}

void WindowManager::createWindow(const std::string& windowName, std::function<void()> initialCode,
    std::function<void()> perFrameCode, int width, int height,
    const std::string& parentWindowName)
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

    newWindow->SetFramebufferSizeCallback([](int width, int height) {});

#ifdef _DEBUG
    std::cout << "Created window: " << windowName << std::endl;
#endif
}

void WindowManager::limitFrameRate(const std::string& windowName, unsigned int targetFPS) {
    for (int i = 0; i < windows.size(); ++i) {
        if (windows[i]->GetTitle() == windowName) {

            windows[i]->targetFPS = targetFPS;
            return;
        }
    }
}

int WindowManager::getRefreshRate(const std::string& windowName) {
	for (int i = 0; i < windows.size(); ++i) {
		if (windows[i]->GetTitle() == windowName) {
			return windows[i]->GetMonitorRefreshRate();
		}
	}
	return 0;
}

void WindowManager::vSync(const std::string& windowName) {
    for (int i = 0; i < windows.size(); ++i) {
        if (windows[i]->GetTitle() == windowName) {
            windows[i]->VSync();
            return;
        }
    }
}

void WindowManager::run() {
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
        if (allClosed) break;
    }
}

void WindowManager::close() {
    for (auto& window : windows) {
        window->Close();
    }
    windows.clear(); // Release resources
    perFrameCodes.clear();
}