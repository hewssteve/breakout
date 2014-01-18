#ifndef _VERTEXARRAY_H
#define _VERTEXARRAY_H

#include <map>

#include "SDLBase.h"
#include "BufferObject.h"

typedef struct
{
    GLint num_elements;
    GLenum type;
    GLboolean normalized;
    GLsizei offset; 
} VertexAttribute;

typedef std::map<GLuint, VertexAttribute> AttributeSet;
typedef std::pair<GLuint, VertexAttribute> AttrPair;
/*
 * Some common vertex attribute formats
 */
typedef struct
{
    glm::vec4 position;
    glm::vec3 normal;
    glm::vec2 tex_coord;
} Vertex4_3_2;

typedef struct
{
    glm::vec2 position;
    glm::vec2 tex_coord;
} Vertex2_2;

class VertexArray
{
  public:

    VertexArray();
    VertexArray(const BufferObject& vertbuf, const BufferObject& _elembuf,
        const AttributeSet& attrs, GLsizei stride);

    virtual ~VertexArray();

    GLuint getID(void) const;

  private:

    GLuint _id;

};

#endif
