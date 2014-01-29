#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include <string>

#include "ComponentSystem.h"
#include "ShaderProgram.h"

class RenderSystem: public ComponentSystem
{

  public:

    RenderSystem();
    virtual ~RenderSystem();

    virtual void init(void);

    virtual void update(float time, float dt, float alpha);

  private:

    ShaderProgram _shaderprogram;

};

#endif
