#include "Component.h"

Component::Component(const std::string& entityID) :
    _entityID(entityID)
{

}

Component::~Component()
{

}

const std::string& Component::getEntityID(void) const
{
  return _entityID;
}

