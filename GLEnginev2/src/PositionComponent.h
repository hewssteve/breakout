
#ifndef POSITIONCOMPONENT_H_
#define POSITIONCOMPONENT_H_

#include "SDLBase.h"
#include "Component.h"

class PositionComponent: public Component
{
    
  private:
    
    glm::vec3 _position;
    
    
  public:
    PositionComponent(const std::string& entityID, const glm::vec3& initial_pos);
    virtual ~PositionComponent();
    
    const glm::vec3& getPosition() const { return _position; } 
    
    void setPosition(const glm::vec3& position)
    {
      _position = position;
    }
    
};

#endif
