#pragma once

#ifdef _DEBUG
#include <iostream>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ShaderProgram.h"
#include "ThreadedObjectLoader.h"
#include <memory>
#include <mutex>

class DynamicWindow : public std::enable_shared_from_this<DynamicWindow> {
private:
    static std::shared_ptr<DynamicWindow> instance;
    std::shared_ptr<ShaderProgram> shaderProgram;
    std::shared_ptr<ThreadedObjectLoader> objectLoader;

    static std::once_flag initInstanceFlag;

    GLFWwindow* internalContext;
    GLFWwindow* writerContext;
    GLFWwindow* drawContext;

    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 0.0f;

    DynamicWindow();
public:
    static std::shared_ptr<DynamicWindow> getInstance() {
        std::call_once(initInstanceFlag, []() {
            instance = std::shared_ptr<DynamicWindow>(new DynamicWindow());
            });
        return instance;
    }

    ~DynamicWindow();

    bool shouldClose();
    void close();
    bool isPressed(int glfw_key);
    void setBackgroundColor(float r, float g, float b, float a);
    GLFWwindow* getWindow();

    void draw();

    void createGLFWInternalContext();
    void createGLFWWriterContext();
    void createGLFWDrawContext();

	void deleteGLFWInternalContext();
	void deleteGLFWWriterContext();
	void deleteGLFWDrawContext();

    void setGLFWContextInternal();
    void setGLFWContextWriter();
    void setGLFWContextDraw();

    DynamicWindow(const DynamicWindow&) = delete;
    DynamicWindow& operator=(const DynamicWindow&) = delete;
};

void framebuffer_size_callback(GLFWwindow* internalWindow, int width, int height);