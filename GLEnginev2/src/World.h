/*
 * World.h
 *
 *  Created on: 08/01/2014
 *      Author: stephen
 */

#ifndef WORLD_H_
#define WORLD_H_

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

#endif /* WORLD_H_ */
