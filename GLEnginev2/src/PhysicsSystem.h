#ifndef _PHYSICSSYSTEM_H_
#define _PHYSICSSYSTEM_H_

#include "ComponentSystem.h"
#include "World.h"

class PhysicsSystem : public ComponentSystem
{

  public:

    PhysicsSystem();
    virtual ~PhysicsSystem();

    virtual void init(void);

    virtual void update(World& world, float time, float dt, float alpha);


};

#endif
