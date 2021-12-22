#pragma once
#include "Minecraft/Core.h"
#include "Minecraft/Game.h"

namespace Minecraft
{
    class Window
    {
        public:
            Window(int width, int height, const char* title);
            ~Window();

            void Run();

        private:
            GLFWwindow * nativeWindow;
            int width;
            int height;

            void ConfigureEventsCallbacks();
            bool shouldClose();
    };
}