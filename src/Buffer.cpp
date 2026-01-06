#pragma once

namespace core {
class Buffer {
public:
  Buffer();
  Buffer(const Buffer &) = delete;
  Buffer(Buffer &&);
  Buffer &operator=(Buffer &) = delete;
  Buffer &operator=(Buffer &&);

private:
};
} // namespace core
