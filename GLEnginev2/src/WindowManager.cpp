#include "WindowManager.h"

WindowManager::WindowManager(){}

WindowManager::WindowManager(int width, int height, bool fullscreen)
:
    _window_width(width),
    _window_height(height),
    _isFullscreen(fullscreen),
    _window(NULL),
    _GLcontext(NULL)
{

}

bool WindowManager::init(void)
{
  bool success = false;

  Uint32 flags = SDL_INIT_EVERYTHING;

  if(SDL_Init(flags) < 0)
  {

  }
  else
  {



  }
  return success;
}


WindowManager::~WindowManager()
{

}

