#include "Application.hpp"

#include <thread>
#include <chrono>

namespace Jupiter::Core {
Application *Application::s_Instance = nullptr;

Application::Application() {
  s_Instance = this;
  m_Window = std::make_unique<Window>("Jupiter Engine", 1280, 720);
  m_AssetManager.Init();
};

Application::~Application() {
  m_AssetManager.Shutdown();
  s_Instance = nullptr;
}

void Application::Run() {
  // float lastFrameTime = 0.0f;

  // const float targetFPS = 60.0f;
  // const float targetFrameTime = 1.0f / targetFPS;

  // VSync
  glfwSwapInterval(1);

  while (m_running) {
    // float time = (float)glfwGetTime();
    //  Timestep timestep = time - lastFrameTime;

    /*
    if (timestep < targetFrameTime) {
      float sleepTime = targetFrameTime - (float)timestep;

      std::this_thread::sleep_for(
          std::chrono::milliseconds((int)(sleepTime * 1000.0f)));

      time = (float)glfwGetTime();
      timestep = time - lastFrameTime;
    };*/

    // lastFrameTime = time;

    m_Window->OnUpdate();

    if (m_Window->ShouldClose())
      m_running = false;
  }
}

}; // namespace Jupiter::Core