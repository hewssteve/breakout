#ifndef GL_BUFFER_H_
#define GL_BUFFER_H_

#include "breakout/util.h"

namespace gl {

class Buffer {
  public:
    Buffer();
    Buffer(GLenum target, GLsizeiptr size, GLenum usage);

    virtual ~Buffer();

    void bufferData(const GLvoid* data);

    void bufferData(const GLvoid* data, int offset, int size);

    GLuint id(void) const {
      return id_;
    }

    GLenum usage(void) const {
      return usage_;
    }

    GLenum target(void) const {
      return target_;
    }

    GLsizeiptr size(void) const {
      return size_;
    }

  private:
    GLuint id_;
    GLenum usage_;
    GLenum target_;
    GLsizeiptr size_;

    DISALLOW_COPY_AND_ASSIGN(Buffer);
};

}
#endif // GL_GLBUFFER_H_
