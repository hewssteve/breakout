#ifndef _POSITIONCOMPONENT_H_
#define _POSITIONCOMPONENT_H_

#include <glm/glm.hpp>

#include "Component.h"

class PositionComponent: public Component
{

  public:

    PositionComponent();
    PositionComponent(const glm::vec3& initial_pos);
    virtual ~PositionComponent();

    glm::vec3 _pos;

};

#endif
