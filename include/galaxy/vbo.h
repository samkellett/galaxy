#ifndef GXY_VBO_H
#define GXY_VBO_H

#include <cstdint>
#include <vector>

namespace gxy {

class VBO {
public:
  VBO(int size = 0);
  ~VBO();

  unsigned int id() const;

  void bind(int type);
  void upload(int drawing);
  void clear();

  void addData(void *data, unsigned int size);
  const std::vector<uint8_t> &data() const;

  void *mapBuffer(int usage);
  void *mapBuffer(int usage, unsigned int offset, unsigned int length);
  bool unmapBuffer();

private:
  unsigned int id_;
  int type_;
  bool uploaded_;

  std::vector<uint8_t> data_;
};

} // namespace gxy

#endif // GXY_VBO_H
