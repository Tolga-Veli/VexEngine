#pragma once

#include <memory>
#include "Window.hpp"
#include "AssetManager.hpp"
#include "Timestep.hpp"

namespace Jupiter::Core {

class Application {
public:
  Application();
  virtual ~Application();

  void Run();

  static Application &Get() { return *s_Instance; }
  Assets::AssetManager &GetAssetManager() { return m_AssetManager; }

  Window &GetWindow() { return *m_Window; }

private:
  bool m_running = true;
  static Application *s_Instance;

  std::unique_ptr<Window> m_Window;
  Assets::AssetManager m_AssetManager;
};

Application *CreateApplication();
}; // namespace Jupiter::Core