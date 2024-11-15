#include <stdexcept>
#include <iostream>

import WindowManager;

int main() {
	WindowManager manager;
    
    manager.createWindow("Main Window", [] {
            // Initial Code
            glClearColor((float)135/255, (float)206/255, (float)235/255, 1.0);
        },
        []() {
            // Render Loop
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        });

    // Run the main loop
    manager.run();

    // Step 3: Windows are automatically destroyed when they go out of scope
    return 0;
}