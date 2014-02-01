#include "Mesh.h"

Mesh::Mesh(){}

Mesh::Mesh(PrimType type, const GLvoid* vertices, GLuint vertex_count,
    const GLushort* indices, GLuint indice_count,
    AttributeSet attrs, GLsizei stride)
:
  _vertex_count(vertex_count),
  _indice_count(indice_count),
  _vert_buffer(BufferObject::ARRAY_BUFFER, 0, GL_STATIC_DRAW),
  _elem_buffer(BufferObject::ELEMENT_BUFFER, 0, GL_STATIC_DRAW),
  _vao(_vert_buffer, _elem_buffer, attrs, stride)
{
  switch(type)
  {
    case Mesh::TRIANGLES:
      _primitive = GL_TRIANGLES;
      break;
    case Mesh::POINTS:
      _primitive = GL_POINTS;
      break;
  };
}

Mesh::~Mesh()
{
}

GLenum Mesh::getPrimitive(void) const
{
  return _primitive;
}

GLuint Mesh::getVertexCount(void) const
{
  return _vertex_count;
}

GLuint Mesh::getIndiceCount(void) const
{
  return _indice_count;
}

const BufferObject& Mesh::getVertBuffer(void) const
{
  return _vert_buffer;
}

const BufferObject& Mesh::getElementBuffer(void) const
{
  return _elem_buffer;
}

const VertexArray& Mesh::getVAO(void) const
{
  return _vao;
}
