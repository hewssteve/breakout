#include "PhysicsSystem.h"

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

  for(std::vector<Entity>::iterator i = entlist.begin(); i != entlist.end();
      ++i)
  {
    Entity ent = *i;

    int pos_handle = ent.getCompHandle(Entity::POSITION);
    int mov_handle = ent.getCompHandle(Entity::MOVEMENT);

  }


}

