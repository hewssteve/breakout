#include "MeshComponent.h"

MeshComponent::MeshComponent(){}

MeshComponent::MeshComponent(PrimType type, const GLvoid* vertices,
    GLuint vertex_count, const GLushort* indices, 
    GLuint indice_count, AttributeSet attrs, GLsizei stride)
:
    Component(),
    _vertex_count(vertex_count),
    _indice_count(indice_count),
    _vert_buffer(GL_ARRAY_BUFFER, 0, GL_STATIC_DRAW),
    _elem_buffer(GL_ELEMENT_ARRAY_BUFFER, 0, GL_STATIC_DRAW),
    _vao(_vert_buffer, _elem_buffer, attrs, stride)
{
  switch(type)
  {
    case PrimType::TRIANGLES:
      _primitive = GL_TRIANGLES;
      break;
    case PrimType::POINTS:
      _primitive = GL_POINTS;
      break;
  };
}

MeshComponent::~MeshComponent(){}

GLuint MeshComponent::getVAOID(void) const
{
  return _vao.getID();
}

GLenum MeshComponent::getPrimitive(void) const
{
  return _primitive;
}

GLuint MeshComponent::getVertexCount(void) const
{
  return _vertex_count;
}

GLuint MeshComponent::getIndiceCount(void) const
{
  return _indice_count;
}

const BufferObject& MeshComponent::getVertBuffer(void) const
{
  return _vert_buffer;
}

const BufferObject& MeshComponent::getElementBuffer(void) const
{
  return _elem_buffer;
}
