#include "breakout/scene.h"

Scene::Scene()
{

}

void Scene::update(float t, float dt)
{
  for (std::vector<entity>::iterator i = entlist_.begin(); i != entlist_.end();
      ++i)
  {
    entity e = *i;
    int ent_position_handle = e.comp_handles[POSITION];
    position_t ent_pos = ent_position_list_.at(ent_position_handle);


  }
}
