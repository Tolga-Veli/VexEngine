#pragma once

#include <string>
#include <cstdint>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Jupiter::Core {
class Window {
public:
  Window(const std::string title, uint32_t width, uint32_t height);
  ~Window();

  void Init();
  void Shutdown();

  void OnUpdate();
  bool ShouldClose() const;

  void *GetNativeWindow() const { return m_WindowHandle; }

private:
  GLFWwindow *m_WindowHandle;
  struct WindowData {
    std::string Title;
    uint32_t Width, Height;
  } m_Data;
};
}; // namespace Jupiter::Core
