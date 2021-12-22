#include "Minecraft/Window/Window.h"

void KeyPressedCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        printf("You pressed E key\n");
}

void JoystickCallback(int joystickId, int event)
{
    printf("%d\n", event);

    if (event == GLFW_CONNECTED)
    {
        printf("Joystick connected: %d\n", joystickId);
        const char* joystickName = glfwGetGamepadName(joystickId);
        printf("%s\n", joystickName);
    }
    else if (event == GLFW_DISCONNECTED)
        printf("Joystick disconnected: %d\n", joystickId);
    
    GLFWgamepadstate state;

    if (glfwGetGamepadState(joystickId, &state))
    {
        if (state.buttons[GLFW_GAMEPAD_BUTTON_CROSS])
        {
            printf("Pressionou um botão\n");
        }
    }
}

void errorCallback( int error, const char *msg ) {
    std::string s;
    s = " [" + std::to_string(error) + "] " + msg + '\n';
    std::cerr << s << std::endl;
}

namespace Minecraft
{
    Window::Window(int width, int height, const char* title)
    {
        glfwSetErrorCallback(errorCallback);

        if(!glfwInit())
        {
            printf("Failed to initialize GLFW\n");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        nativeWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
        width        = width;
        height       = height;

        if(nativeWindow == nullptr)
        {
            printf("Failed to create GLFW window\n");
            glfwTerminate();
        }

        glfwMakeContextCurrent(nativeWindow);
        ConfigureEventsCallbacks();
    }

    Window::~Window() {
        glfwDestroyWindow(nativeWindow);
        glfwTerminate();
    }

    void Window::ConfigureEventsCallbacks()
    {
        glfwSetKeyCallback(nativeWindow, KeyPressedCallback);
        glfwSetJoystickCallback(JoystickCallback);
    }

    void Window::Run()
    {
        while(!shouldClose()) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(nativeWindow);
            glfwPollEvents();
        }
    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(nativeWindow);
    }
}