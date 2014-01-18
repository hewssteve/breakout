#include "BufferObject.h"

BufferObject::BufferObject(){}

BufferObject::BufferObject(BufTarget target, GLsizeiptr size, GLenum usage)
:
 _usage(usage),
 _size(size)
{
  if(target == BufTarget::ARRAY_BUFFER)
  {
    _target = GL_ARRAY_BUFFER;
  } else if(target == BufTarget::ELEMENT_BUFFER)
  {
    _target = GL_ELEMENT_ARRAY_BUFFER;
  }
  
  glGenBuffers(1, &_id);
  glBindBuffer(_target, _id);
  glBufferData(_target, size, NULL, usage);
  glBindBuffer(_target, 0);
  checkGLError(__LINE__, "BufferObject::BufferObject()");
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
  glBindBuffer(_target, _id);
  glBufferSubData(_target, 0, _size, data);
  glBindBuffer(_target, 0);
  checkGLError(__LINE__, "BufferObject::bufferData()");
}
