#include "BufferObject.h"

BufferObject::BufferObject(GLenum target, GLsizeiptr size, GLenum usage)
{
  GLuint vbo;
  glGenBuffers(1, &vbo);
  _id = vbo;
  _target = target;
  _size = size;
  _usage = usage;

  glBindBuffer(_target, _id);
  glBufferData(_target, size, NULL, usage);
  glBindBuffer(_target, 0);
  checkGLError(__LINE__, "BufferObject::BufferObject()");
}

BufferObject::~BufferObject()
{
  glDeleteBuffers(1,&_id);
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
  glBindBuffer(_target, _id);

  glBufferSubData(_target, 0, _size, data);

  glBindBuffer(_target, 0);

  checkGLError(__LINE__, "BufferObject::bufferData()");
}
