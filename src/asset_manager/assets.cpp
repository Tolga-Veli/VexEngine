#include "assets.hpp"

namespace core {
std::vector<std::string> asset_manager::_assets{};
std::map<std::string, std::shared_ptr<void>> asset_manager::_textures{};
std::map<std::string, std::shared_ptr<void>> asset_manager::_materials{};
std::map<std::string, std::shared_ptr<void>> asset_manager::_shaders{};
std::map<std::string, std::shared_ptr<void>> asset_manager::_audio{};

void asset_manager::add_texture(const std::filesystem::path &path) {}
void asset_manager::add_material(const std::filesystem::path &path) {}
void asset_manager::add_shader(const std::filesystem::path &path) {}
void asset_manager::add_audio(const std::filesystem::path &path) {}

asset_manager::asset_manager() {}
asset_manager::~asset_manager() {}

}; // namespace core
