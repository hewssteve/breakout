#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <string>

#include "Component.h"

class World
{

  private:

    std::vector<Component> _complist;

  public:
    World();
    virtual ~World();

};

#endif
