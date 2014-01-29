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

  if(SDL_Init(flags) > 0)
  {
    success = true;
  }
  else
  {

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_Window* window = SDL_CreateWindow("Test", 0,
         0, width, height, 0);

    setFullscreen(fullscreen);
  }

  return success;
}

void WindowManager::setFullscreen(bool fullscreen)
{
  _isFullscreen = fullscreen;

  SDL_SetWindowFullscreen(_window, 0);

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

