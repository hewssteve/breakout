#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <iostream>

#include "WindowManager.h"

WindowManager::WindowManager(){}

WindowManager::~WindowManager()
{
  SDL_GL_DeleteContext(_GLcontext);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

bool WindowManager::init(int width, int height, bool fullscreen)
{
  static const char* WINDOW_TITLE = "OpenGL";

  static const int INIT_WINDOWX = 100;
  static const int INIT_WINDOWY = 100;

  static const int INIT_WINDOW_WIDTH = 800;
  static const int INIT_WINDOW_HEIGHT = 600;

  static const int MAJOR_VERSION = 3;
  static const int MINOR_VERSION = 3;

  static const Uint32 WINDOW_FLAGS = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

  _window_height = height;
  _window_width = width;

  Uint32 flags = SDL_INIT_EVERYTHING;

  if(SDL_Init(flags) > 0)
  {
    return false;
  }
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  _window = SDL_CreateWindow(WINDOW_TITLE, INIT_WINDOWX,
  INIT_WINDOWY, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT, WINDOW_FLAGS);

  if (_window == NULL)
  {
    std::cout << "ERROR: SDL_CreateWindow() failed: ";
    std::cout << SDL_GetError() << std::endl;
    return false;
  }

  _GLcontext = SDL_GL_CreateContext(_window);
  if (_GLcontext == NULL)
  {
    std::cout << "ERROR: SDL_GL_CreateContext() failed: ";
    std::cout << SDL_GetError();
    std::cout << "-- requested GL version: " << MAJOR_VERSION << "."
        << MINOR_VERSION << std::endl;
    return false;
  }

  glewExperimental = GL_TRUE;
  GLenum error = glewInit();
  if (error != GLEW_OK)
  {
    std::cout << "ERROR: glewInit() failure : ";
    std::cout << glewGetErrorString(error) << std::endl;
    return false;
  }

  setFullscreen(fullscreen);


  return true;
}

void WindowManager::swapGLBuffer(void)
{
  std::cout << "swap buffer " << std::endl;
  SDL_GL_SwapWindow(_window);
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

