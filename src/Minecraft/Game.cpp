#include "Minecraft/Game.h"

namespace Minecraft
{
    Game::Game()
    {

    }

    Game* Game::GetInstance()
    {
        if (instance == nullptr)
            instance = new Game();
        
        return instance;
    }

    void Game::ProcessInput()
    {
        GLFWgamepadstate gamepadState;
        
        if (glfwGetGamepadState(GLFW_JOYSTICK_1, &gamepadState))
        {
            if (gamepadState.buttons[GLFW_GAMEPAD_BUTTON_CIRCLE])
                printf("Pressed Circle button\n");
            
            if (gamepadState.buttons[GLFW_GAMEPAD_BUTTON_CROSS])
                printf("Pressed X button\n");

            if (gamepadState.buttons[GLFW_GAMEPAD_BUTTON_SQUARE])
                printf("Pressed Square button\n");

            if (gamepadState.buttons[GLFW_GAMEPAD_BUTTON_TRIANGLE])
                printf("Pressed Triangle button\n");
            
            if (gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_X] <= -0.15 ||
                gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_X] >= 0.15)
            {
                printf("Left axis X: %f\n", gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_X]);
            }

            if (gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_Y] <= -0.15 ||
                gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_Y] >= 0.15)
            {
                printf("Left axis Y: %f\n", gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_Y]);
            }
        }
    }
}