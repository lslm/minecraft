#include "Minecraft/Window/Window.h"

namespace Minecraft
{
    Window* Window::createWindow(int width, int height, const char* title)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        Window* window = new Window();

        window->nativeWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
        window->width        = width;
        window->height       = height;

        if(window == nullptr)
        {
            printf("Failed to create GLFW window\n");
            glfwTerminate();
            return nullptr;
        }

        glfwMakeContextCurrent(window->nativeWindow);

        return window;
    }
}