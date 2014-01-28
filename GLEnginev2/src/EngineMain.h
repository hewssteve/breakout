#ifndef _ENGINEMAIN_H_
#define _ENGINEMAIN_H_

#include <vector>

#include "ComponentSystem.h"

class EngineMain
{

  public:

    EngineMain();
    virtual ~EngineMain();

    void update(float dt) const;
    void mainLoop(void) const;

    void addSystem(void);

  private:

    std::vector<ComponentSystem> _systems;

};

#endif
