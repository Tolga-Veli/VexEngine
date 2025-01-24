#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace core {
struct window_t {
  GLFWwindow *window = nullptr;
  const std::string_view title;
  const uint16_t width, height;

  explicit window_t(std::string _t, uint16_t _w, uint16_t _h)
      : title(_t), width(_w), height(_h) {}
};

class render_handler {
public:
  render_handler(std::string title, uint16_t width, uint16_t height)
      : _window(title, width, height) {
    if (!init())
      shutdown();
  }
  render_handler(render_handler &) = delete;
  ~render_handler() { shutdown(); };

private:
  window_t _window;

  const std::string_view _fragsh;
  const std::string_view _vertsh;

  bool init();
  void shutdown();
  void main_loop();
};
}; // namespace core
