#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
int main() {
  glfwInit();

  GLFWwindow *window = glfwCreateWindow(800, 600, "TEST", 0, 0);
  if (!window) {
    std::cout << "Window was a nullptr\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Glad couldn't be loaded\n";
    return -1;
  }

  float arr[] = {0.5f, -0.5f, 0.5f, 0.5f, 1.0f, 0.0f};
  unsigned int a;
  glGenBuffers(1, &a);
  glBindBuffer(GL_ARRAY_BUFFER, a);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), arr, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glViewport(0, 0, 800, 600);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
