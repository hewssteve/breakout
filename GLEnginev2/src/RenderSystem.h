
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include "ComponentSystem.h"

class RenderSystem: public ComponentSystem
{
  public:
    RenderSystem();
    virtual ~RenderSystem();
    
    virtual void init(void);
    
    virtual void update(float dt);
    
};

#endif
