#pragma once
#include "Minecraft/Core.h"

namespace Minecraft
{
    struct Window
    {
        GLFWwindow * nativeWindow;
        int width;
        int height;

        static Window* createWindow(int width, int height, const char* title);
    };
}