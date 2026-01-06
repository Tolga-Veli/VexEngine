#pragma once

#include <filesystem>
#include <map>
#include <memory>
#include <vector>

namespace core {
class AssetManager {
public:
  static void AddTexture(const std::filesystem::path &path);
  static void AddMaterial(const std::filesystem::path &path);
  static void AddShader(const std::filesystem::path &path);
  static void AddAudio(const std::filesystem::path &path);

  AssetManager();
  AssetManager(const AssetManager &) = delete;
  AssetManager &operator=(const AssetManager &) = delete;
  ~AssetManager();

private:
};

}; // namespace core
