#ifndef _BUFFEROBJECT_H_
#define _BUFFEROBJECT_H_

#include <gl/glew.h>

class BufferObject
{

  public:
    
    enum BufferTarget
    {
      ARRAY_BUFFER,
      ELEMENT_BUFFER
    };
    
    BufferObject();
    BufferObject(BufferTarget target, GLsizeiptr size, GLenum usage);
    virtual ~BufferObject();

    GLuint getID(void) const;
    GLenum getTarget(void) const;

    void bufferData(const GLvoid* data);
    void bufferData(const GLvoid* data, int offset, int size);

  private:

    GLuint _id;
    
    GLenum _usage;  
    GLsizeiptr _size;
    GLenum _target;

};

#endif 
