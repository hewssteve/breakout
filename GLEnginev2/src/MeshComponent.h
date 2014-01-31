#ifndef _MESHCOMPONENT_H_
#define _MESHCOMPONENT_H_

#include <GL/glew.h>

#include "VertexArray.h"
#include "BufferObject.h"
#include "Component.h"

typedef struct
{
  GLuint vertcount;
  GLuint indicecount;
} MeshInfo;

class MeshComponent : public Component
{

  public:

    enum PrimType
    {
      TRIANGLES,
      POINTS
    };

    MeshComponent();    
    MeshComponent(PrimType type, const GLvoid* vertices,
        GLuint vertex_count, const GLushort* indices, 
        GLuint indice_count, AttributeSet atrrs, GLsizei stride);

    virtual ~MeshComponent();

    GLuint getVAOID(void) const;

    GLenum getPrimitive(void) const;
    GLuint getVertexCount(void) const;
    GLuint getIndiceCount(void) const;

    const BufferObject& getVertBuffer(void) const;
    const BufferObject& getElementBuffer(void) const;


  private:

    GLuint _vertex_count;
    GLuint _indice_count;

    BufferObject _vert_buffer;
    BufferObject _elem_buffer;

    VertexArray _vao;
    GLenum _primitive;

};

#endif
