#include "BufferObject.h"

BufferObject::BufferObject(){}

BufferObject::BufferObject(BufferTarget target, GLsizeiptr size, GLenum usage)
:
    _usage(usage),
    _size(size)
{
  switch(target)
  {
    case BufferObject::ARRAY_BUFFER:
      _target = GL_ARRAY_BUFFER;
      break;
    case BufferObject::ELEMENT_BUFFER:
      _target = GL_ELEMENT_ARRAY_BUFFER;
      break;
  };
  glGenBuffers(1, &_id);
  glBindBuffer(_target, _id);
  glBufferData(_target, _size, NULL, _usage);
  glBindBuffer(_target, 0);
}

BufferObject::~BufferObject()
{
  glDeleteBuffers(1, &_id);
}

GLuint BufferObject::getID(void) const
{
  return _id;
}

GLenum BufferObject::getTarget(void) const
{
  return _target;
}

void BufferObject::bufferData(const GLvoid* data)
{
  bufferData(data, 0, _size);
}

void BufferObject::bufferData(const GLvoid* data, int offset, int size)
{
  glBindBuffer(_target, _id);
  glBufferSubData(_target, offset, size, data);
  glBindBuffer(_target, 0);
}
