#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>

#include "Logging.hpp"

namespace Jupiter::Utils {

inline std::string ReadFile(const std::filesystem::path &path) {
  std::string result;
  std::ifstream in(path, std::ios::in | std::ios::binary);

  if (in) {
    in.seekg(0, std::ios::end);
    int size = in.tellg();

    if (size != -1) {
      result.resize(size);
      in.seekg(0, std::ios::beg);
      in.read(&result[0], size); // Read everything at once
      in.close();
    } else
      J_ERROR("Could not read file: {}", path.string());

  } else
    J_ERROR("Could not open file: {}", path.string());
  return result;
}
} // namespace Jupiter::Utils