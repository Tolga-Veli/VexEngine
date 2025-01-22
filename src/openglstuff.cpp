#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

static unsigned int CompileShader(const std::string &source,
                                  unsigned int type) {
  unsigned int id = glCreateShader(GL_VERTEX_SHADER);
  const char *src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  return id;
}

static int CreateShader(const std::string &vertexShader,
                        const std::string &fragmentShader) {
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
  unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);
  return 0;
}

int main(int argc, char *argv[]) {
  glfwInit();

  GLFWwindow *window = glfwCreateWindow(640, 800, "gl", NULL, NULL);
  if (!window) {
    std::cout << "Window couldn't be created\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  float ver[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), ver, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}
