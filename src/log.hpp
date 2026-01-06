#pragma once

#include <iostream>
#include <print>
#include <format>

namespace core {
#define VEX_INFO(...) std::println("INFO: {}", __VA_ARGS__);
#define VEX_WARNING(...) std::println("WARNING: {}", __VA_ARGS__)
#define VEX_ERROR(...) std::println("ERROR: {}", __VA_ARGS__)
#define VEX_FATAL(...)                                                         \
  std::println("FATAL: {}", __VA_ARGS__);                                      \
  core::engine::terminate()
} // namespace core