#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <unordered_map>

namespace Jupiter {
namespace Render {
enum class ShaderType : uint32_t {
  None = 0,
  Vertex = GL_VERTEX_SHADER,
  Fragment = GL_FRAGMENT_SHADER,
  Geometry = GL_GEOMETRY_SHADER,
  Compute = GL_COMPUTE_SHADER
};

inline constexpr std::string_view to_string(ShaderType type) {
  switch (type) {
  case ShaderType::None:
    return "None";
  case ShaderType::Vertex:
    return "Vertex";
  case ShaderType::Fragment:
    return "Fragment";
  case ShaderType::Geometry:
    return "Geometry";
  case ShaderType::Compute:
    return "Compute";
  default:
    return "";
  }
}

class Shader {
public:
  Shader(const std::unordered_map<ShaderType, std::string> &sources);
  ~Shader();

  void Bind() const;
  void Unbind() const;

private:
  unsigned int m_ShaderProgram;

  unsigned int
  CreateProgram(const std::unordered_map<ShaderType, std::string> &sources);
  unsigned int CompileShader(ShaderType type, const std::string &source);
};
} // namespace Render

namespace Assets {
namespace fs = std::filesystem;

class ShaderLoader {
public:
  static std::shared_ptr<Render::Shader> LoadFromFile(const fs::path &path);
};
} // namespace Assets
} // namespace Jupiter