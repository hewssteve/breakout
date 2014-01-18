#include "VertexArray.h"

VertexArray::VertexArray(){}

VertexArray::VertexArray(const BufferObject& vertbuf, const BufferObject& _elembuf,
    const AttributeSet& attrs, GLsizei stride)
{
  glGenVertexArrays(1, &_id);
  glBindVertexArray(_id);

  glBindBuffer(vertbuf.getTarget(), vertbuf.getID());

  for(AttributeSet::const_iterator i = attrs.begin(); i != attrs.end(); ++i)
  {
    glEnableVertexAttribArray(i->first); 
    VertexAttribute attr = i->second;
    glVertexAttribPointer(i->first, attr.num_elements, attr.type, 
        attr.normalized, stride,
        reinterpret_cast<GLvoid*>(attr.offset));   
  }
  glBindBuffer(_elembuf.getTarget(), _elembuf.getID());

  glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
  glDeleteVertexArrays(1, &_id);
}

GLuint VertexArray::getID(void) const
{
  return _id;
}
