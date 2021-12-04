#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

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

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow * window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Minecraft", nullptr, nullptr);

  if(window == nullptr)
  {
    printf("Failed to create GLFW window\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    printf("Faild to initialize Glad\n");
    glfwTerminate();
    return -1;
  }

  glViewport(0,0, WINDOW_WIDTH, WINDOW_HEIGHT);

  while(!glfwWindowShouldClose(window))
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}