
#include "BufferObject.h"

#include <iostream>

const GLenum BufferObject::DEFAULT_TARGET = GL_ARRAY_BUFFER;

BufferObject::BufferObject()
{

}

BufferObject::BufferObject(GLenum target, GLsizeiptr size,  GLenum usage)
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
  checkGLError(__LINE__,"BufferObject::BufferObject()");
}

BufferObject::~BufferObject()
{
  std::cout << "Buffer destructor" << std::endl;
  //glDeleteBuffers(1,&_id);
  checkGLError(__LINE__,"BufferObject::~BufferObject()");
}

void BufferObject::bufferData(const GLvoid* data)
{
  glBindBuffer(_target, _id);
  
  glBufferSubData(_target, 0, _size, data);
  
  glBindBuffer(_target, 0);
  
  checkGLError(__LINE__,"BufferObject::bufferData()");
}
