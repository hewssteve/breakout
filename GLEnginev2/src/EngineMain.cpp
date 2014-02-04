#include "EngineMain.h"

#include <SDL2/SDL.h>

// temp for debug
#include <iostream>

EngineMain::EngineMain(WindowManager* window)
{
  this->_window = window;
}

EngineMain::~EngineMain()
{
  for(std::vector<ComponentSystem*>::iterator i = _systems.begin();
      i != _systems.end(); ++i)
  {
    delete *i;
  }
}

bool EngineMain::init(void)
{
  /*
   * init component systems
   */
  _rendersys.init();
  _world.init();
  _systems.push_back(new PhysicsSystem());


  return true;
}

void EngineMain::update(float time, float dt, float alpha)
{
  for(std::vector<ComponentSystem*>::iterator i = _systems.begin();
      i != _systems.end(); ++i)
  {
    ComponentSystem* sys = *i;
    sys->update(_world, time, dt, alpha);
  }
}

void EngineMain::mainLoop(void)
{
  bool quit = false;

  // the current time since the program opened
  Uint32 current_time = _window->getTime();

  // the time the engine has been running for
  float t = 0.0f;

  float accumulator = 0.0f;
  // the fixed dt of the simulation
  const float dt = 0.05f;
  const float max_frame_time = 0.25f;

  while(!quit)
  {
    // poll events here
    // TODO: Replace with generic event structure independent of SDL
    SDL_Event event;
    while(_window->pollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_WINDOWEVENT:
          break;
        case SDL_QUIT:
          quit = true;
          break;
        default:
          // event handler
          break;
      };
    }
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
    const double alpha = accumulator / dt;
    _rendersys.update(_world, t, dt, alpha);
    _window->swapGLBuffer();

  }
}
