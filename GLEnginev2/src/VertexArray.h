#ifndef _VERTEXARRAY_H
#define _VERTEXARRAY_H

#include "SDLBase.h"
#include "BufferObject.h"

typedef struct
{

    GLuint num_elements;
    GLsizei offset;

} Attribute;

typedef glm::vec3 vec3_t;
typedef glm::vec2 vec2_t;

typedef struct
{
    vec3_t position;
    vec3_t normal;
    vec2_t tex_coord;

} Vertex3_3_2;

typedef struct
{

    vec2_t position;
    vec2_t tex_coord;

} Vertex2_2;

/******************************************************************************
 *
 *   Vertex Array 
 *
 *   
 *
 *
 *****************************************************************************/
class VertexArray
{
  public:

    VertexArray(GLenum primitive, const GLvoid* vertices, GLuint vert_count,
        const GLushort* indices, GLuint index_count);

    virtual ~VertexArray();

    GLuint getID(void) const;
    GLenum getPrimitive(void) const;
    GLuint getVertCount(void) const;
    GLuint getIndexCount(void) const;

    const BufferObject& getVertBuffer(void) const;
    const BufferObject& getElementBuffer(void) const;

  private:

    GLuint _id;
    GLuint _vert_count;
    GLuint _index_count;

    GLenum _primitive;

    BufferObject _vert_buffer;
    BufferObject _elem_buffer;

};

#endif
