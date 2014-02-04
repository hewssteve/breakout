#include "Entity.h"

unsigned Entity::MAX_COMPONENTS = 10;
int Entity::NO_COMPONENT = -1;

Entity::Entity()
{
  std::fill_n(_comp_handles, MAX_COMPONENTS, NO_COMPONENT);

}

Entity::~Entity(){}

int Entity::getCompHandle(CompType type)
{
  return _comp_handles[type];
}
