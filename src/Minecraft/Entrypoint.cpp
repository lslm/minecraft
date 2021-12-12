#include "Minecraft/Core.h"
#include "Minecraft/Window/Window.h"

using namespace Minecraft;

const unsigned int WINDOW_WIDTH = 1200;
const unsigned int WINDOW_HEIGHT = 800;

void errorCallback( int error, const char *msg ) {
    std::string s;
    s = " [" + std::to_string(error) + "] " + msg + '\n';
    std::cerr << s << std::endl;
}

int main()
{
  glfwSetErrorCallback(errorCallback);
  if(!glfwInit())
  {
    printf("Failed to initialize GLFW\n");
    return -1;
  }

  Window* window = Window::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Minecraft Clone");

  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    printf("Faild to initialize Glad\n");
    glfwTerminate();
    return -1;
  }

  glViewport(0, 0, window->width, window->height);

  while(!glfwWindowShouldClose(window->nativeWindow))
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window->nativeWindow);
    glfwPollEvents();
  }

  glfwTerminate();
}