#include <stdexcept>
#include <iostream>

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

    // Run the main loop
    manager->run();

    return 0;
}