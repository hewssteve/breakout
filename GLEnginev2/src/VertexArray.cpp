#include "VertexArray.h"

#include <iostream>
// TODO: way of specifying vertex attributes
VertexArray::VertexArray(GLenum primitive, const GLvoid* vertices,
    GLuint vert_count, const GLushort* indices, GLuint index_count)
{
  _vert_count = vert_count;
  _primitive = primitive;
  _index_count = index_count;

  int element_size = sizeof(Vertex3_3_2);

  // create the buffers 
  _vert_buffer(GL_ARRAY_BUFFER, element_size * vert_count,
  GL_STATIC_DRAW);
  _vert_buffer.bufferData(vertices);

  if (indices != NULL)
  {
    _elem_buffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * index_count,
        GL_STATIC_DRAW);
    _elem_buffer.bufferData(static_cast<const GLvoid*>(indices));
  }

  glGenVertexArrays(1, &_id);
  glBindVertexArray(_id);

  glBindBuffer(_vert_buffer.getTarget(), _vert_buffer.getID());

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, element_size, 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, element_size,
      reinterpret_cast<GLvoid*>(sizeof(vec3_t)));
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, element_size,
      reinterpret_cast<GLvoid*>(2 * sizeof(vec3_t)));

  if (indices != NULL)
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
