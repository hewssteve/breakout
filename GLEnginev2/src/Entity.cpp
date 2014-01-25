#include "Entity.h"

const unsigned Entity::MAX_COMPONENTS = 10;

Entity::Entity()
:
  _id("TODO_ID")
{
}

Entity::~Entity(){}

const std::string& Entity::getID(void) const
{
  return _id;
}
