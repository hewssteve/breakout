#ifndef _ENGINEMAIN_H_
#define _ENGINEMAIN_H_

#include <vector>

#include "ComponentSystem.h"

class EngineMain
{

  public:

    EngineMain();
    virtual ~EngineMain();

    bool init(void);
    void update(float time, float dt, float alpha);
    void mainLoop(void);

    void addSystem(void);

  private:

    std::vector<ComponentSystem> _systems;
    RenderSystem _rendersys;

    WindowManager _window;

};

#endif
