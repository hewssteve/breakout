#include "PositionComponent.h"

PositionComponent::PositionComponent(const std::string& entityID,
    const glm::vec3& initial_pos) :
    Component(entityID), _position(initial_pos)
{
}

PositionComponent::~PositionComponent()
{
}

