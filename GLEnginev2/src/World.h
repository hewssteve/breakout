#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

#include "Component.h"
#include "MeshComponent.h"
#include "PositionComponent.h"
#include "MovementComponent.h"
#include "Entity.h"

class World
{

  public:

    static unsigned int MAX_ENTITIES;


    World();
    virtual ~World();

    void init(void);

    void addEntity();
    void removeEntity();
    
    const std::vector<Entity>& getEntityList(void) const;

    const std::vector<MeshComponent>& getMeshComponents(void) const;
    const std::vector<PositionComponent>& getPositionComponents(void) const;
    const std::vector<MovementComponent>& getMovementComponents(void) const;

  private:

    std::vector<Entity> _entity_list;
    
    // component arrays
    std::vector<PositionComponent> _positions_list;
    std::vector<MovementComponent> _movement_list;
    std::vector<MeshComponent> _mesh_list;

};

#endif
