#include "MovementComponent.h"

MovementComponent::MovementComponent(const std::string& entityID) :
    Component(entityID), _velocity(0.0f), _accel(0.0f)
{

}

MovementComponent::~MovementComponent()
{

}

