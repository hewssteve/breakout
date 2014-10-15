#include <SDL2/SDL.h>

#include "breakout/engine.h"

#define FIXED_TIMESTEP 0

Engine::Engine()
{
  
}

Engine::~Engine()
{
  
}

bool Engine::init(WindowManager* window)
{
  if(window == NULL) return false;
  this->_window = window;

  return true;
}

void Engine::mainLoop(void)
{
bool quit_flag = false;
Uint32 current_time = _window->getTime();
float t = 0.0f;
#if FIXED_TIMESTEP
  float accumulator = 0.0f;
  const float DT = 1.0f/25.0f;
  const float MAX_FRAME_DT = 0.1f;
#endif
  while (!quit_flag)
  {
    SDL_Event event;
    while (_window->pollEventQueue(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          quit_flag = true;
          break;
        default:
          break;
      }
    }
  const Uint32 new_time = _window->getTime();
  float frame_time = (new_time - current_time) * 0.001f;
  current_time = new_time;
#if FIXED_TIMESTEP
  if (frame_time > MAX_FRAME_DT)
  {
    frame_time = MAX_FRAME_DT;
  }
  accumulator += frame_time;

  while (accumulator >= DT)
  {
    accumulator -= DT;
    update(t, DT);
    t += DT;
  }

  const double alpha = accumulator / DT;
  render(alpha);
#else
  t += frame_time;
  this->update(t, frame_time);
  this->render();
  
#endif
//  SDL_RenderPresent(renderer);
  }
}


void Engine::update(float t, float dt)
{
  
}

void Engine::render()
{
  
}
