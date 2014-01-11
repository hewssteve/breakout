#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "SDLBase.h"

/******************************************************************************
 *
 *   Texture 
 *
 *
 *
 *****************************************************************************/
class Texture
{
  public:
    Texture();
    Texture(SDL_Surface* surface, GLenum format, GLint internalformat);
    virtual ~Texture();

    GLuint getID() const
    {
      return _tex_id;
    }

  private:

    GLuint _tex_id;

    // format, width, height etc

};

#endif
