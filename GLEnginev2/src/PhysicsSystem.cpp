#include "PhysicsSystem.h"

#include <iostream>
#include <glm/glm.hpp>

#include "MovementComponent.h"
#include "PositionComponent.h"

PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::init(void)
{

}

void PhysicsSystem::update(World& world, float time, float dt, float alpha)
{
  std::vector<Entity> entlist = world.getEntityList();

  std::vector<MovementComponent> move_complist = world.getMovementComponents();
  std::vector<PositionComponent> pos_complist = world.getPositionComponents();

  for(std::vector<Entity>::iterator i = entlist.begin(); i != entlist.end();
      ++i)
  {
    Entity ent = *i;

    int pos_handle = ent.getCompHandle(Entity::POSITION);
    int mov_handle = ent.getCompHandle(Entity::MOVEMENT);

    if(mov_handle != Entity::NO_COMPONENT && pos_handle != Entity::NO_COMPONENT)
    {
      MovementComponent* v = NULL;
      PositionComponent* d = NULL;

      d = &move_complist[mov_handle];
      v = &pos_complist[pos_handle];

      assert(v != NULL);
      assert(d != NULL);

      v->_dx += v->_dv * dt;
      d->_pos += v->_dx * dt;

    }

  }

}

