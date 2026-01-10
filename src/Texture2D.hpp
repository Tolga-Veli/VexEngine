#pragma once

#include <filesystem>

#include "Logging.hpp"

namespace Jupiter {
namespace Render {
class Texture2D {
public:
  Texture2D(const std::filesystem::path &path);
  ~Texture2D();

private:
};
} // namespace Render

namespace Assets {
namespace fs = std::filesystem;

class Texture2DLoader {
public:
  static std::shared_ptr<Render::Texture2D> LoadFromFile(const fs::path &path);

private:
};

} // namespace Assets
}; // namespace Jupiter