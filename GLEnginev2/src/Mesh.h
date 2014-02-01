#ifndef _MESH_H_
#define _MESH_H_

#include <gl/glew.h>

#include "VertexArray.h"
#include "BufferObject.h"

class Mesh
{
  public:

    enum PrimType
    {
      TRIANGLES,
      POINTS
    };

    Mesh();
    Mesh(PrimType type, const GLvoid* vertices, GLuint vertex_count,
        const GLushort* indices, GLuint indice_count,
        AttributeSet attrs, GLsizei stride);
    virtual ~Mesh();

    GLenum getPrimitive(void) const;
    GLuint getVertexCount(void) const;
    GLuint getIndiceCount(void) const;

    const BufferObject& getVertBuffer(void) const;
    const BufferObject& getElementBuffer(void) const;

    const VertexArray& getVAO(void) const;

  private:


    GLuint _vertex_count;
    GLuint _indice_count;

    BufferObject _vert_buffer;
    BufferObject _elem_buffer;

    VertexArray _vao;

    GLenum _primitive;

};

#endif
