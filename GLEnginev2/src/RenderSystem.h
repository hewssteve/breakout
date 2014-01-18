#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include <string>

#include "ComponentSystem.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "FileUtils.h"

class RenderSystem: public ComponentSystem
{
  public:
    RenderSystem();
    virtual ~RenderSystem();
    
    virtual void init(void);
    
    virtual void update(float dt);
    
  private:
    
    ShaderProgram _shaderprogram;
    
    
    
};

#endif
