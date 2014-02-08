#ifndef _MOVEMENTCOMPONENT_H_
#define _MOVEMENTCOMPONENT_H_

#include <glm/glm.hpp>

#include "Component.h"

class MovementComponent: public Component
{

  public:

    MovementComponent();
    virtual ~MovementComponent();

    glm::vec3 _dx;
    glm::vec3 _dv;



};

#endif 
