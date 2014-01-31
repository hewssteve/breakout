#include "EngineMain.h"

// temp for debug
#include <iostream>

EngineMain::EngineMain(WindowManager* window)
{
  this->_window = window;
}

EngineMain::~EngineMain()
{
}

bool EngineMain::init(void)
{
  /*
   * init component systems
   */
  return true;
}

void EngineMain::update(float time, float dt, float alpha)
{
  /*
  for(std::vector<ComponentSystem*>::iterator i = _systems.begin();
      i != _systems.end(); ++i)
  {
    //i->update(time, dt, alpha);
  }
  */
}

void EngineMain::mainLoop(void)
{
  bool quit = false;

  // the current time since the program opened
  Uint32 current_time = _window->getTime();

  std::cout << "time: " << current_time << std::endl;

  // the time the engine has been running for
  float t = 0.0f;

  float accumulator = 0.0f;
  // the fixed dt of the simulation
  const float dt = 0.1f;
  const float max_frame_time = 0.25f;

  while(!quit)
  {
    // poll events here




    // get the time
    const Uint32 new_time = _window->getTime();
    // calculate the frame time in seconds
    float frame_time = new_time - current_time * 0.001f;
    current_time = new_time;
    /*
     *  avoid le spiral of death
     */
    if(frame_time > max_frame_time)
    {
      frame_time = max_frame_time;
    }

    accumulator += frame_time;

    while(accumulator >= dt)
    {
      accumulator -= dt;

      update(t, dt, 0.0f);

      t += dt;
    }
    // interpolate how far we are to the next frame
    const double alpha = accumulator / dt;

    _rendersys.update(t, dt, alpha);
    _window->swapGLBuffer();

  }
}
