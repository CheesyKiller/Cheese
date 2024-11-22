#include "DynamicWindow.h"
#include <iostream>
#include <thread>
#include <mutex>

std::shared_ptr<DynamicWindow> DynamicWindow::instance = nullptr;
std::once_flag DynamicWindow::initInstanceFlag;

void checkOpenGLError(const std::string& location) {
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        std::cerr << "OpenGL error " << err << " at " << location << std::endl;
    }
}

DynamicWindow::DynamicWindow() {
    std::cout << "Initializing GLFW" << std::endl;
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    std::cout << "Setting GLFW context version" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    createGLFWInternalContext();
    std::cout << "Making context current" << std::endl;
    glfwMakeContextCurrent(internalContext);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    std::cout << "Setting viewport" << std::endl;
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(internalContext, framebuffer_size_callback);

    std::cout << "Setting up shader program" << std::endl;
    shaderProgram = ShaderProgram::getInstance();
    std::cout << "Setting up object loader" << std::endl;
    objectLoader = ThreadedObjectLoader::getInstance();
    std::cout << "DynamicWindow initialized" << std::endl;
}

DynamicWindow::~DynamicWindow() {
    std::cout << "Destroying GLFW window" << std::endl;
    deleteGLFWInternalContext();
    glfwTerminate();
}

bool DynamicWindow::shouldClose() {
    return glfwWindowShouldClose(internalContext);
}

void DynamicWindow::close() {
    glfwSetWindowShouldClose(internalContext, true);
}

bool DynamicWindow::isPressed(int glfw_key) {
    return glfwGetKey(internalContext, glfw_key) == GLFW_PRESS;
}

void DynamicWindow::setBackgroundColor(float red, float green, float blue, float alpha) {
    this->r = red;
    this->g = green;
    this->b = blue;
    this->a = alpha;
    std::cout << "Background color set to: " << red << ", " << green << ", " << blue << ", " << alpha << std::endl;
}

void DynamicWindow::draw() {
    glfwMakeContextCurrent(internalContext);
    std::cout << "Drawing with background color: " << r << ", " << g << ", " << b << ", " << a << std::endl;

    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram->draw();

    glfwSwapBuffers(internalContext);
    glfwPollEvents();

    checkOpenGLError("draw");
}

void DynamicWindow::createGLFWInternalContext() {
    internalContext = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (internalContext == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
}

void DynamicWindow::createGLFWWriterContext() {
    writerContext = glfwCreateWindow(1, 1, "Writer Context", nullptr, internalContext);
    if (!writerContext) {
        std::cerr << "Failed to create writer OpenGL context" << std::endl;
        throw std::runtime_error("Failed to create writer OpenGL context");
    }
    glfwMakeContextCurrent(writerContext);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD for writer context" << std::endl;
        throw std::runtime_error("Failed to initialize GLAD for writer context");
    }
    checkOpenGLError("createGLFWWriterContext");
}

void DynamicWindow::createGLFWDrawContext() {
    drawContext = glfwCreateWindow(1, 1, "Draw Context", nullptr, internalContext);
    if (!drawContext) {
        std::cerr << "Failed to create draw OpenGL context" << std::endl;
        throw std::runtime_error("Failed to create draw OpenGL context");
    }
    glfwMakeContextCurrent(drawContext);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD for draw context" << std::endl;
        throw std::runtime_error("Failed to initialize GLAD for draw context");
    }
    checkOpenGLError("createGLFWDrawContext");
}

void DynamicWindow::deleteGLFWInternalContext() {
    if (internalContext) {
        glfwDestroyWindow(internalContext);
        internalContext = nullptr;
    }
}

void DynamicWindow::deleteGLFWWriterContext() {
    if (writerContext) {
        std::thread([this]() {
            glfwDestroyWindow(writerContext);
            writerContext = nullptr;
            }).join();
    }
}

void DynamicWindow::deleteGLFWDrawContext() {
    if (drawContext) {
        std::thread([this]() {
            glfwDestroyWindow(drawContext);
            drawContext = nullptr;
            }).join();
    }
}

void DynamicWindow::setGLFWContextWriter() {
    glfwMakeContextCurrent(writerContext);
    checkOpenGLError("setGLFWContextWriter");
}

void DynamicWindow::setGLFWContextDraw() {
    glfwMakeContextCurrent(drawContext);
    checkOpenGLError("setGLFWContextDraw");
}

void DynamicWindow::setGLFWContextInternal() {
    glfwMakeContextCurrent(internalContext);
    checkOpenGLError("setGLFWContextInternal");
}

GLFWwindow* DynamicWindow::getWindow() {
    return internalContext;
}

void framebuffer_size_callback(GLFWwindow* internalWindow, int width, int height) {
    glViewport(0, 0, width, height);
}