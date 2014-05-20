#ifndef BREAKOUT_SCENE_H_
#define BREAKOUT_SCENE_H_

#include "breakout/util.h"

enum CompHandle
{
  POSITION = 0,
  MOVEMENT,
  RENDER,
  COLLISION,
  DISTINCT_COMPONENTS
};

struct entity
{
    unsigned int id;
    int comp_handles[DISTINCT_COMPONENTS];
};

struct position_t
{
    glm::vec2 pos;
};

struct movement_t
{
    glm::vec2 dx;
    glm::vec2 dv;
};

struct render_t
{
    // pointer to render object
};

struct collision_t
{

};

class Scene
{

  public:

    Scene();

    // update all game objects in scene
    void update(float t, float dt);
    // TODO pass information on how to create entity
    void addEntity();

    void removeEntity(unsigned int id);

  private:

    std::vector<entity> entlist_;

    std::vector<position_t> ent_position_list_;
    std::vector<movement_t> ent_movement_list_;

    DISALLOW_COPY_AND_ASSIGN(Scene);

};

#endif /* BREAKOUT_SCENE_H_ */
