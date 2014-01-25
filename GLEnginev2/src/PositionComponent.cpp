#include "PositionComponent.h"

PositionComponent::PositionComponent(){}

PositionComponent::PositionComponent(const glm::vec3& initial_pos)
:
    Component(),
    _position(initial_pos)
{
}

PositionComponent::~PositionComponent(){}

const glm::vec3& PositionComponent::getPosition() const
{
  return _position;
}

void PositionComponent::setPosition(const glm::vec3& position)
{
  _position = position;
}

