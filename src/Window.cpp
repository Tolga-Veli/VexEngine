
#include "Logging.hpp"
#include "Window.hpp"

namespace Jupiter::Core {

Window::Window(const std::string Title, uint32_t Width, uint32_t Height) {
  m_Data = {Title, Width, Height};
  Init();
}

Window::~Window() { Shutdown(); }

void Window::Init() {
  int success = glfwInit();
  if (!success) {
    J_ERROR("Could not initialize GLFW!");
    return;
  }

  glfwSetErrorCallback([](int error, const char *desc) {
    J_ERROR("GLFW Error ({0}: {1}", error, desc);
  });

  m_WindowHandle = glfwCreateWindow(m_Data.Width, m_Data.Height,
                                    m_Data.Title.c_str(), nullptr, nullptr);
  if (!m_WindowHandle) {
    J_ERROR("Could not create GLFW window!");
    return;
  }

  glfwMakeContextCurrent(m_WindowHandle);

  int version = gladLoadGL(glfwGetProcAddress);
  if (version == 0) {
    J_ERROR("Failed to initialize GLAD!");
    return;
  }
  J_INFO("Glad version {0}", version);

  glfwSetWindowUserPointer(m_WindowHandle, &m_Data);
  glfwSetFramebufferSizeCallback(
      m_WindowHandle, [](GLFWwindow *window, int width, int height) {
        auto &data = *(WindowData *)glfwGetWindowUserPointer(window);
        data.Width = width;
        data.Height = height;

        glViewport(0, 0, width, height);

        J_INFO("Window resized to: {0}x{1}", width, height);
      });
}

void Window::Shutdown() {
  if (m_WindowHandle) {
    J_INFO("Destroying GLFW Window: {0}", m_Data.Title);
    glfwDestroyWindow(m_WindowHandle);
  }

  glfwTerminate();
  J_INFO("GLFW Terminated successfully.");
}

void Window::OnUpdate() {
  glfwPollEvents();

  // TODO: abstract into its own renderer class
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glfwSwapBuffers(m_WindowHandle);
}

bool Window::ShouldClose() const {
  return glfwWindowShouldClose(m_WindowHandle);
}
}; // namespace Jupiter::Core