#include "breakout/gl/buffer.h"

#include <cassert>

namespace gl {

Buffer::Buffer() {
}

Buffer::Buffer(GLenum target, GLsizeiptr size, GLenum usage) :
    usage_(usage), target_(target), size_(size) {
  glGenBuffers(1, &id_);
  glBindBuffer(target_, id_);
  glBufferData(target_, size_, NULL, usage_);
  glBindBuffer(target_, 0);
  GL_CHECK_ERROR;
}

Buffer::~Buffer() {
  glDeleteBuffers(1, &id_);
  GL_CHECK_ERROR;
}

void Buffer::bufferData(const GLvoid* data) {
  bufferData(data, 0, size_);
}

void Buffer::bufferData(const GLvoid* data, int offset, int size) {
  assert(data != NULL);
  assert(offset <= size_);
  assert(size <= size_);
  glBindBuffer(target_, id_);
  glBufferSubData(target_, offset, size, data);
  glBindBuffer(target_, 0);
  GL_CHECK_ERROR;
}

}
