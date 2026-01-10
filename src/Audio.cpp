#include "Audio.hpp"
#include "Logging.hpp"

namespace Jupiter {
namespace Core {

Audio::Audio(const std::filesystem::path &path) {
  J_INFO("Tried creating a Audio {}", path.string());
}
Audio::~Audio() {}

} // namespace Core

namespace Assets {
std::shared_ptr<Core::Audio> AudioLoader::LoadFromFile(const fs::path &path) {
  J_INFO("Tried loading an Audio {}", path.string());
  return nullptr;
}
} // namespace Assets
} // namespace Jupiter