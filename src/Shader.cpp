#include <vector>

#include "Shader.hpp"
#include "Utils.hpp"

namespace Jupiter {
namespace Render {
Shader::Shader(const std::unordered_map<ShaderType, std::string> &sources) {
  m_ShaderProgram = CreateProgram(sources);
}

Shader::~Shader() { glDeleteProgram(m_ShaderProgram); }

unsigned int Shader::CreateProgram(
    const std::unordered_map<ShaderType, std::string> &sources) {
  unsigned int program = glCreateProgram();
  std::vector<uint32_t> shaderIDs;

  for (auto &[type, source] : sources) {
    uint32_t id = CompileShader(type, source);
    if (id != 0) {
      glAttachShader(program, id);
      shaderIDs.push_back(id);
    }
  }

  glLinkProgram(program);

  int status = 0;
  glGetProgramiv(program, GL_LINK_STATUS, &status);
  if (!status) {
    int length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

    std::vector<char> info(length);
    glGetProgramInfoLog(program, length, &length, info.data());
    glDeleteProgram(program);

    J_ERROR("Shader linking Failed: {}", info.data());
    return 0;
  }

  for (auto id : shaderIDs) {
    glDetachShader(program, id);
    glDeleteShader(id);
  }

  return program;
}

unsigned int Shader::CompileShader(ShaderType type, const std::string &source) {
  unsigned int id = glCreateShader((unsigned int)type);
  const char *src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int success = 0;
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if (!success) {
    int length = 0;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

    std::vector<char> info(length);
    glGetShaderInfoLog(id, length, &length, info.data());

    J_ERROR("{} Shader compilation failed:\n{}", to_string(type), info.data());
    glDeleteProgram(id);
    return 0;
  }
  return id;
}

void Shader::Bind() const { glUseProgram(m_ShaderProgram); }
void Shader::Unbind() const { glUseProgram(0); }
} // namespace Render

namespace Assets {
std::shared_ptr<Render::Shader>
ShaderLoader::LoadFromFile(const fs::path &path) {
  std::unordered_map<Render::ShaderType, std::string> shaderSrcs;

  static auto StringToType = [](const std::string &type) -> Render::ShaderType {
    if (type == "vertex")
      return Render::ShaderType::Vertex;
    else if (type == "fragment")
      return Render::ShaderType::Fragment;
    else if (type == "geometry")
      return Render::ShaderType::Geometry;
    else if (type == "compute")
      return Render::ShaderType::Compute;
    return Render::ShaderType::None;
  };

  std::string source = Utils::ReadFile(path);

  std::string_view token = "#type";
  size_t pos = source.find(token, 0);
  while (pos != std::string::npos) {
    size_t eol = source.find_first_of("\r\n", pos);
    size_t beg = pos + token.length() + 1;
    std::string type = source.substr(beg, eol - beg);

    size_t nextLinePos = source.find_first_not_of("\r\n", eol);
    pos = source.find(token, nextLinePos);

    shaderSrcs[StringToType(type)] =
        (pos == std::string::npos)
            ? source.substr(nextLinePos)
            : source.substr(nextLinePos, pos - nextLinePos);
  }
  return std::make_shared<Render::Shader>(shaderSrcs);
}
} // namespace Assets
} // namespace Jupiter