#include "EngineMain.h"

EngineMain::EngineMain()
{
}

EngineMain::~EngineMain()
{
}

bool EngineMain::init(void)
{
  const int width = 800;
  const int height = 600;
  const bool fullscreen = false;

  if(!_window.init(width, height, fullscreen))
  {
    std::cout << "window init failed." << std::endl;
    return false;
  }

  /*
   * init component systems
   */





  return true;
}

void EngineMain::update(float time, float dt, float alpha)
{
  for(std::vector<ComponentSystem>::iterator i = _systems.begin();
      i != _systems.end(); ++i)
  {
    i->update(time, dt, alpha);
  }
}

void EngineMain::mainLoop(void)
{
  bool quit = false;

  // the current time since the program opened
  Uint32 current_time = _window.getTime();

  // the time the engine has been running for
  float t = 0.0f;
  //
  float accumulator = 0.0f;
  // the fixed dt of the simulation
  const float dt = 0.1f;
  const float max_frame_time = 0.25f;

  while(!quit)
  {
    // get the time
    const Uint32 new_time = _window.getTime();
    // calculate the frame time in seconds
    float frame_time = new_time - current_time * 0.001f;
    current_time = new_time;

    /*
     * put a limit on how long to step forward the simulation
     * to avoid le spiral of death
     */
    frame_time = frame_time > max_frame_time ? max_frame_time : frame_time;

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

  }
}
