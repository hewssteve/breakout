#include "MovementComponent.h"

MovementComponent::MovementComponent()
:
    Component(),
    _velocity(0.0f),
    _accel(0.0f)
{
}

MovementComponent::~MovementComponent(){}

const glm::vec3& MovementComponent::getVelocity(void) const
{
  return _velocity;
}

const glm::vec3& MovementComponent::getAcceleration(void) const
{
  return _accel;
}

void MovementComponent::setVelocity(const glm::vec3& velocity)
{
  _velocity = velocity;
}

void MovementComponent::setAcceleration(const glm::vec3& accel)
{
  _accel = accel;
}
