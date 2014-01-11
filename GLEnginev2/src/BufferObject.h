#ifndef BUFFEROBJECT_H_
#define BUFFEROBJECT_H_

#include "SDLBase.h"

class BufferObject
{
  public:
    BufferObject();
    BufferObject(GLenum target, GLsizeiptr size, GLenum usage);
    ~BufferObject();

    GLuint getID() const
    {
      return _id;
    }

    GLenum getTarget() const
    {
      return _target;
    }

    void bufferData(const GLvoid* data);

  private:

    GLuint _id;
    GLenum _target;

    GLenum _usage;
    GLsizeiptr _size;

    static const GLenum DEFAULT_TARGET;
};

#endif 
