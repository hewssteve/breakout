#include "World.h"

unsigned int World::MAX_ENTITIES = 1000;

World::World()
:
    _entity_list(MAX_ENTITIES),
    _positions_list(MAX_ENTITIES),
    _movement_list(MAX_ENTITIES),
    _mesh_list(MAX_ENTITIES)
{
}

World::~World()
{
}

void World::init(void)
{

}

void World::addEntity()
{


}
void World::removeEntity()
{


}

const std::vector<Entity>& World::getEntityList(void) const
{
  return _entity_list;
}

const std::vector<MeshComponent>& World::getMeshComponents(void) const
{
  return _mesh_list;
}
const std::vector<PositionComponent>& World::getPositionComponents(void) const
{
  return _positions_list;
}
const std::vector<MovementComponent>& World::getMovementComponents(void) const
{
  return _movement_list;
}
