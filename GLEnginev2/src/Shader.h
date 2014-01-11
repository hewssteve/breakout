#ifndef SHADER_H
#define SHADER_H

#include "SDLBase.h"

/******************************************************************************
 *
 *   Shader
 *
 *
 *
 *****************************************************************************/
class Shader
{
  public:

    Shader();
    Shader(GLenum type);
    ~Shader();

    GLuint getID() const
    {
      return _id;
    }

    GLenum getType() const
    {
      return _type;
    }

    const GLchar* compile(const GLchar* source);

    
    
    
  private:

    GLuint _id;
    GLenum _type;

};

#endif
