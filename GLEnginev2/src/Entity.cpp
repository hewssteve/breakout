#include "Entity.h"

unsigned Entity::MAX_COMPONENTS = 10;

Entity::Entity()
{
  std::fill_n(_comp_handles, MAX_COMPONENTS, -1);

}

Entity::~Entity(){}

int Entity::getCompHandle(CompType type)
{
  return _comp_handles[type];
}
