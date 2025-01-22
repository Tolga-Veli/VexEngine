#include "../include/rendering.hpp"
#include <iostream>

namespace core {
bool render_handler::init() {
  glfwInit();

  _window.window = glfwCreateWindow(_window.width, _window.height,
                                    _window.title.begin(), 0, 0);
  if (!_window.window) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(_window.window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return false;
  }

  glViewport(0, 0, _window.width, _window.height);

  return true;
}

void render_handler::main_loop() {}
void render_handler::shutdown() {}
} // namespace core
