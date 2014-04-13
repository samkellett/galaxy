#include "vbo.h"

#include "gfx.h"

namespace gxy {

VBO::VBO(int size) :
  type_(-1),
  uploaded_(false)
{
  gfx::genBuffers(1, &id_);

  if (size > 0) {
    data_.reserve(size);
  }
}

VBO::~VBO()
{
  gfx::deleteBuffers(1, &id_);
}

unsigned int VBO::id() const
{
  return id_;
}

void VBO::bind(int type)
{
  type_ = type;
  gfx::bindBuffer(type_, id_);
}

void VBO::upload(int drawing) {
  gfx::bufferData(type_, data_.size(), &data_[0], drawing);

  uploaded_ = true;
  data_.clear();
}

void VBO::clear()
{
  gfx::deleteBuffers(1, &id_);

  uploaded_ = false;
  data_.clear();
}

void VBO::addData(void *data, unsigned int size)
{
  data_.insert(data_.end(), static_cast<uint8_t *>(data), static_cast<uint8_t *>(data) + size);
}

const std::vector<uint8_t> &VBO::data() const
{
  return data_;
}

void *VBO::mapBuffer(int usage)
{
  if (!uploaded_) {
    return nullptr;
  }

  return gfx::mapBuffer(type_, usage);
}

void *VBO::mapBuffer(int usage, unsigned int offset, unsigned int length)
{
  if (!uploaded_) {
    return NULL;
  }

  return gfx::mapBufferRange(type_, offset, length, usage);
}

bool VBO::unmapBuffer()
{
  return gfx::unmapBuffer(type_);
}

} // namespace gxy
