#include "WindowManager.h"

WindowManager::WindowManager(){}

/*
WindowManager::WindowManager(int width, int height, bool fullscreen)
:
    _window_width(width),
    _window_height(height),
    _isFullscreen(fullscreen),
    _window(NULL),
    _GLcontext(NULL)
{

}
*/
bool WindowManager::init(int width, int height, bool fullscreen)
{
  bool success = false;

  this->_window_height = height;
  this->_window_width = width;

  Uint32 flags = SDL_INIT_EVERYTHING;

  if(SDL_Init(flags) < 0)
  {

  }

  setFullscreen(fullscreen);


  return success;
}

void WindowManager::setFullscreen(bool fullscreen)
{
  _isFullscreen = fullscreen;

}

void WindowManager::setCaption(const std::string& caption)
{

}

Uint32 WindowManager::getTime(void)
{
  return SDL_GetTicks();
}

WindowManager::~WindowManager()
{

}

