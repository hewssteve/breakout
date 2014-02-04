#ifndef _COMPONENTSYSTEM_H_
#define _COMPONENTSYSTEM_H_

#include "World.h"

class ComponentSystem
{

  public:

    ComponentSystem();

    virtual ~ComponentSystem();

    virtual void init(void) = 0;

    virtual void update(World& world, float time, float dt, float alpha) = 0;

};

#endif
