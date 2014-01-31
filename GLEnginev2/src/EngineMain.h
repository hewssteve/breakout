#ifndef _ENGINEMAIN_H_
#define _ENGINEMAIN_H_

#include <vector>

#include "ComponentSystem.h"
#include "RenderSystem.h"
#include "WindowManager.h"

class EngineMain
{

  public:

    EngineMain(WindowManager* window);
    virtual ~EngineMain();

    bool init(void);
    void update(float time, float dt, float alpha);
    void mainLoop(void);
    void addSystem(ComponentSystem* system);

    void setWindowManager(WindowManager* window);

  private:

    std::vector<ComponentSystem*> _systems;

    WindowManager* _window;

    RenderSystem _rendersys;



};

#endif
