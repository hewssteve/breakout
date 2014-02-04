#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include "ComponentSystem.h"
#include "ShaderProgram.h"
#include "World.h"

class RenderSystem: public ComponentSystem
{

  public:

    RenderSystem();
    virtual ~RenderSystem();

    virtual void init(void);

    virtual void update(World& world, float time, float dt, float alpha);

  private:

    ShaderProgram _shaderprogram;

};

#endif
