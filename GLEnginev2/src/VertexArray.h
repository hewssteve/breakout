#ifndef ENGINE_VERTEXARRAY_H
#define ENGINE_VERTEXARRAY_H

#include "SDLBase.h"
#include "BufferObject.h"

typedef struct {

    GLuint num_elements;
    GLsizei offset;

} Attribute;

#define VERTEX_3_3_2 0
#define VERTEX_2_2   1

typedef glm::vec3 vec3_t;
typedef glm::vec2 vec2_t;

typedef struct {
    vec3_t position;
    vec3_t normal;
    vec2_t tex_coord;

} Vertex3_3_2;

typedef struct {

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
class VertexArray {
  public:

    VertexArray();
    VertexArray(GLenum primitive, const GLvoid* vertices, GLuint vert_count,
        const GLushort* indices, GLuint index_count);

    ~VertexArray();

    GLuint getID() const {
      return _id;
    }

    GLenum getPrimitive() const {
      return _primitive;
    }

    GLuint getVertCount() const {
      return _vert_count;
    }

    GLuint getIndexCount() const {
      return _index_count;
    }

  private:

    GLuint _id;
    GLuint _vert_count;
    GLuint _index_count;

    GLenum _primitive;

    BufferObject vert_buffer;
    BufferObject elem_buffer;

};

#endif
