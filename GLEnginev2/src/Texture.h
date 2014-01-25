#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "SDLBase.h"

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
