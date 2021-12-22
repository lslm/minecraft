#include "Minecraft/Core.h"

namespace Minecraft
{
    class Game
    {
    public:
        static Game* GetInstance();
        void ProcessInput();

    private:
        Game();
        inline static Game* instance;
    };
}