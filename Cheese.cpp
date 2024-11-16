#include <stdexcept>
#include <iostream>

#ifndef _DEBUG
#include <Windows.h>
#endif

import WindowManager;
import KeyboardInput;

int main() {
	WindowManager* manager = WindowManager::getInstance();

    manager->createWindow("Main Window", [] {
            // Initial Code
            glClearColor((float)135/255, (float)206/255, (float)235/255, 1.0);
        },
        []() {
            // Render Loop
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            if (Input::IsPressed(Input::KEY_1)) {
				std::cout << "1 is pressed" << std::endl;
            }
            if (Input::IsPressed(Input::KEY_2)) {
                std::cout << "2 is pressed" << std::endl;
            }
            if (Input::IsPressed(Input::KEY_ESCAPE)) {
                WindowManager::getInstance()->close();
            }
        });

    const char* version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    const char* vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));

    std::cout << "OpenGL Version: " << version << std::endl;
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "Vendor: " << vendor << std::endl;

    // Run the main loop
    manager->run();

    return 0;
}