#ifndef BREAKOUT_SCENE_H_
#define BREAKOUT_SCENE_H_

#include "breakout/util.h"

#define MAX_ENTITY 10

class Scene 
{

  public:

    Scene();

    void init(int width, int height);
    
    void update(float t, float dt);
    
    void addEntity();

    void removeEntity(unsigned int id);

  private:

    glm::vec2 world_bounds;
    
    glm::vec2 position_list[MAX_ENTITY];
    glm::vec2 velocity_list[MAX_ENTITY];
    
    DISALLOW_COPY_AND_ASSIGN(Scene);

};

#endif /* BREAKOUT_SCENE_H_ */
