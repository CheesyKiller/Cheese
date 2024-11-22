#include <stdexcept>
#include <iostream>

#ifndef _DEBUG
#include <Windows.h>
#endif

//#include "VertexShader.h"

import WindowManager;
import KeyboardInput;
import Shader;
import RenderObject;

int main() {
	WindowManager* manager = WindowManager::getInstance();

    manager->createWindow("Main Window", []() {
        // Initial Code
        },
        []() {
            // Render Loop
            GLAD::glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            GLAD::glClear(GLAD::GL_COLOR_BUFFER_BIT | GLAD::GL_DEPTH_BUFFER_BIT);

            if (Input::IsPressed(Input::KEY_1)) {
                std::cout << "1 is pressed" << std::endl;
            }
            if (Input::IsPressed(Input::KEY_2)) {
                std::cout << "2 is pressed" << std::endl;
            }
            if (Input::IsPressed(Input::KEY_ESCAPE)) {
                WindowManager::getInstance()->close();
            }

			GlobalShader::getInstance()->drawShaderObjects();
        });

	manager->vSync("Main Window");

	Shader shader(VertexShaderSource, FragmentShaderSource, true);

    shader.createObject();

#ifdef _DEBUG
    const char* version = reinterpret_cast<const char*>(GLAD::glGetString(GLAD::GL_VERSION));
    const char* renderer = reinterpret_cast<const char*>(GLAD::glGetString(GLAD::GL_RENDERER));
    const char* vendor = reinterpret_cast<const char*>(GLAD::glGetString(GLAD::GL_VENDOR));

    std::cout << "OpenGL Version: " << version << std::endl;
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "Vendor: " << vendor << std::endl;
#endif

    // Run the main loop
    manager->run();

    return 0;
}