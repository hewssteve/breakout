#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

#include "Component.h"
#include "Entity.h"

class World
{

  public:

    World();
    virtual ~World();

    void addEntity(const Entity& entity);
    void removeEntity(/* some entity handle here (ID)*/);
    
    
  private:

    std::vector<Entity> _entity_list;
    


};

#endif
