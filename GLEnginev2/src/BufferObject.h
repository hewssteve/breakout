#ifndef _BUFFEROBJECT_H_
#define _BUFFEROBJECT_H_

#include "SDLBase.h"

class BufferObject
{
  public:
    BufferObject(GLenum target, GLsizeiptr size, GLenum usage);
    virtual ~BufferObject();

    GLuint getID(void) const;
    GLenum getTarget(void) const;

    void bufferData(const GLvoid* data);

  private:

    GLuint _id;
    GLenum _target;

    GLenum _usage;
    GLsizeiptr _size;

};

#endif 
