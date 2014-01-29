#ifndef _MOVEMENTCOMPONENT_H_
#define _MOVEMENTCOMPONENT_H_

#include <glm/glm.hpp>

#include "Component.h"

class MovementComponent: public Component
{

  public:

    MovementComponent();
    virtual ~MovementComponent();

    const glm::vec3& getVelocity(void) const;
    const glm::vec3& getAcceleration(void) const;

    void setVelocity(const glm::vec3& velocity);
    void setAcceleration(const glm::vec3& accel);

  private:

    glm::vec3 _velocity;
    glm::vec3 _accel;

};

#endif 
