#ifndef _POSITIONCOMPONENT_H_
#define _POSITIONCOMPONENT_H_

#include "SDLBase.h"
#include "Component.h"

class PositionComponent: public Component
{

  public:
    PositionComponent(const std::string& entityID,
        const glm::vec3& initial_pos);
    virtual ~PositionComponent();

    const glm::vec3& getPosition(void) const;
    void setPosition(const glm::vec3& position);

  private:

    glm::vec3 _position;

};

#endif
