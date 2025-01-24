#pragma once

#include <filesystem>
#include <map>
#include <memory>
#include <vector>

namespace core {
class asset_manager {
public:
  static void add_texture(const std::filesystem::path &);
  static void add_material(const std::filesystem::path &);
  static void add_shader(const std::filesystem::path &);
  static void add_audio(const std::filesystem::path &);

  asset_manager();
  asset_manager(const asset_manager &) = delete;
  ~asset_manager();

  asset_manager &operator=(const asset_manager &) = delete;

private:
  bool init();
  void destroy();

  static std::vector<std::string> _assets;
  static std::map<std::string, std::shared_ptr<void>> _textures;
  static std::map<std::string, std::shared_ptr<void>> _materials;
  static std::map<std::string, std::shared_ptr<void>> _shaders;
  static std::map<std::string, std::shared_ptr<void>> _audio;
};

}; // namespace core
