#include "VertexArray.h"

#include <iostream>

VertexArray::VertexArray(){}

// TODO: way of specifying vertex attributes
VertexArray::VertexArray(GLenum primitive, const Vertex4_3_2* vertices,
    GLuint vert_count, const GLushort* indices, GLuint index_count)
:
 _vert_count(vert_count),
 _index_count(index_count),
 _primitive(primitive),
 _vert_buffer(GL_ARRAY_BUFFER, sizeof(Vertex4_3_2) * vert_count, GL_STATIC_DRAW),
 _elem_buffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * index_count, GL_STATIC_DRAW)
{
  // put data in the buffers 
  _vert_buffer.bufferData(static_cast<const GLvoid*>(vertices));
  _elem_buffer.bufferData(static_cast<const GLvoid*>(indices));
  
  glGenVertexArrays(1, &_id);
  glBindVertexArray(_id);

  glBindBuffer(_vert_buffer.getTarget(), _vert_buffer.getID());

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex4_3_2), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex4_3_2),
      reinterpret_cast<GLvoid*>(sizeof(glm::vec3)));
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex4_3_2),
      reinterpret_cast<GLvoid*>(2 * sizeof(glm::vec3)));

  glBindBuffer(_elem_buffer.getTarget(), _elem_buffer.getID());

  glBindVertexArray(0);
}

VertexArray::~VertexArray()
{

}

GLuint VertexArray::getID(void) const
{
  return _id;
}

GLenum VertexArray::getPrimitive(void) const
{
  return _primitive;
}

GLuint VertexArray::getVertCount(void) const
{
  return _vert_count;
}

GLuint VertexArray::getIndexCount(void) const
{
  return _index_count;
}

const BufferObject& VertexArray::getVertBuffer(void) const
{
  return _vert_buffer;
}

const BufferObject& VertexArray::getElementBuffer(void) const
{
  return _elem_buffer;
}
