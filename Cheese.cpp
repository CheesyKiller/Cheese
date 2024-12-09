import GLAD;
import WindowManager;
import Shader;
import ShaderSources;
import RenderObjectBlenderReader;
import KeyboardInput;

#ifndef _DEBUG
#include <Windows.h>
#endif

int main() {
	WindowManager* manager = WindowManager::getInstance();

    manager->createWindow("Main Window", []() {
        GLAD::glEnable(GLAD::GL_BLEND);
        GLAD::glBlendFunc(GLAD::GL_SRC_ALPHA, GLAD::GL_ONE_MINUS_SRC_ALPHA);
		GLAD::glEnable(GLAD::GL_DEPTH_TEST);
        GLAD::glEnable(GLAD::GL_CULL_FACE);
        GLAD::glCullFace(GLAD::GL_BACK);
        },
        []() {
            if (Input::InputManager::GetInstance()->IsPressed(Input::KEY_ESCAPE)) {
                WindowManager::getInstance()->close();
                return; // DONT REMOVE THIS -> BREAKS GLM COMPILED MODULES!!!
            }

            GLAD::glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            GLAD::glClear(GLAD::GL_COLOR_BUFFER_BIT | GLAD::GL_DEPTH_BUFFER_BIT);

            GlobalShader::getInstance()->drawShaderObjects("Main Window", GLAD::gladGetDeltaTime());
        });

	manager->setVSync("Main Window", true);
	Shader shader(VertexShaderSource, FragmentShaderSource, true);
	RenderObject::BlenderReader* reader = RenderObject::BlenderReader::getInstance();
    shader.createObject(reader->read("cube"));

    manager->run();

    return 0;
}