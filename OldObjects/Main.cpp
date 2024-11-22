#include "DynamicWindow.h"

int main() {
    std::shared_ptr<DynamicWindow> window = DynamicWindow::getInstance();
    window->setBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);

    float visibility = 1.0f;

	bool stop = false;
    while (!stop) {
        if (window->isPressed(GLFW_KEY_ESCAPE)) {
			stop = true;
			window->close();
            break;
        }

        if (window->isPressed(GLFW_KEY_UP)) {
            visibility += 0.01f;
            if (visibility > 1.0f) {
                visibility = 1.0f;
            }
        }

        if (window->isPressed(GLFW_KEY_DOWN)) {
            visibility -= 0.01f;
            if (visibility < 0.0f) {
                visibility = 0.0f;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

#ifdef _DEBUG
    std::cout << "Program is terminating" << std::endl;
    std::cout.flush();
#endif

    return 0;
}
