#include "Minecraft/Core.h"
#include "Minecraft/Window/Window.h"

using namespace Minecraft;

const unsigned int WINDOW_WIDTH = 1200;
const unsigned int WINDOW_HEIGHT = 800;

int main()
{
  Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, "Minecraft Clone");

  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    printf("Faild to initialize Glad\n");
    glfwTerminate();
    return -1;
  }

  window.Run();

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}