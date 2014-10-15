
#include "breakout/windowmanager.h"

WindowManager::WindowManager() 
{
  _window = NULL;
}

WindowManager::~WindowManager() 
{
  SDL_DestroyWindow(_window);
}

bool WindowManager::init(const std::string& caption, Uint32 window_flags, int width, int height,
        bool fullscreen)
{
  _window = SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
          width, height, window_flags);
  if (_window == NULL) return false;
  setFullscreen(fullscreen);
  return true;
}

void WindowManager::setCaption(const std::string& caption)
{
  SDL_SetWindowTitle(_window, caption.c_str());
}

void WindowManager::setFullscreen(bool fullscreen)
{
  SDL_SetWindowFullscreen(_window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

bool WindowManager::pollEventQueue(SDL_Event* e)
{
  return SDL_PollEvent(e);
}

Uint32 WindowManager::getTime()
{
  return SDL_GetTicks();
}