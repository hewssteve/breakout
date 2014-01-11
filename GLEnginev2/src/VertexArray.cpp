#include "VertexArray.h"

#include <iostream>

VertexArray::VertexArray()
{  
}

VertexArray::VertexArray(GLenum primitive, 
    const GLvoid* vertices, GLuint vert_count, 
    const GLushort* indices, GLuint index_count)
{
  _vert_count = vert_count;
  _primitive = primitive;
  _index_count = index_count;

  int element_size = sizeof(Vertex3_3_2);
  
  // create the buffers 
  BufferObject vertbuf(GL_ARRAY_BUFFER, element_size * vert_count, GL_STATIC_DRAW);
  vertbuf.bufferData(vertices);

  BufferObject elembuf;
  
  if(indices != NULL){
    elembuf = BufferObject(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * index_count, GL_STATIC_DRAW);
    elembuf.bufferData(static_cast<const GLvoid*>(indices));
  }
  
  //std::cout << "wat : " << *((GLfloat*)vertices) << std::endl;
  
  glGenVertexArrays(1, &_id);
  glBindVertexArray(_id);

  glBindBuffer(vertbuf.getTarget(),vertbuf.getID());

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);
  
  glVertexAttribPointer(0, 3,GL_FLOAT, GL_FALSE, element_size, 0);
  glVertexAttribPointer(1, 3,GL_FLOAT, GL_FALSE, element_size, 
      reinterpret_cast<GLvoid*>(sizeof(vec3_t)));
  glVertexAttribPointer(2, 2,GL_FLOAT, GL_FALSE, element_size, 
      reinterpret_cast<GLvoid*>(2 * sizeof(vec3_t))); 

  if(indices != NULL)
    glBindBuffer(elembuf.getTarget(), elembuf.getID());
  
  glBindVertexArray(0);
}

VertexArray::~VertexArray()
{

}
