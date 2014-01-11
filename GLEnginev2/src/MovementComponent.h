#ifndef _MOVEMENTCOMPONENT_H_
#define _MOVEMENTCOMPONENT_H_

#include "SDLBase.h"
#include "Component.h"

class MovementComponent: public Component
{

  private:

    glm::vec3 _velocity;
    glm::vec3 _accel;

  public:
    MovementComponent(const std::string& entityID);
    virtual ~MovementComponent();

};

#endif 
