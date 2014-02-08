#include "PositionComponent.h"

PositionComponent::PositionComponent(){}

PositionComponent::PositionComponent(const glm::vec3& initial_pos)
:
    Component(),
    _pos(initial_pos)
{
}

PositionComponent::~PositionComponent(){}
