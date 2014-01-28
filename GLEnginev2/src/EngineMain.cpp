#include "EngineMain.h"

EngineMain::EngineMain()
{

}

EngineMain::~EngineMain()
{
}

void EngineMain::update(float dt) const
{

}


void EngineMain::mainLoop(void) const
{

  bool quit = false;


  while(!quit)
  {
    /*
     * run update methods of component systems in order:
     *
     * - input
     * - logic/physics
     * - render
     *
     *
     */
    // get time since last update
    float dt;

    // update systems
    update(dt);


  }




}
