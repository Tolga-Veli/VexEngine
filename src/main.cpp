#include "Application.hpp"

Jupiter::Core::Application *Jupiter::Core::CreateApplication() {
  return new Jupiter::Core::Application();
}

int main() {
  auto app = Jupiter::Core::CreateApplication();
  app->Run();
  delete app;
}