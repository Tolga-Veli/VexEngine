#include "Texture2D.hpp"

namespace Jupiter {
namespace Render {
Texture2D::Texture2D(const std::filesystem::path &path) {
  J_INFO("Tried creating a Texture2D {}", path.string());
}
Texture2D::~Texture2D() {}

}; // namespace Render

namespace Assets {
std::shared_ptr<Render::Texture2D>
Texture2DLoader::LoadFromFile(const fs::path &path) {
  J_INFO("Tried loading Texture2D: {}", path.string());
  return nullptr;
}
} // namespace Assets
}; // namespace Jupiter