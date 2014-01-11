#include <iostream>

#include "SDLBase.h"

static bool quit_flag = false;

static const char* WINDOW_TITLE = "OpenGL";

static const int INIT_WINDOWX = 100;
static const int INIT_WINDOWY = 100;

static const int INIT_WINDOW_WIDTH = 800;
static const int INIT_WINDOW_HEIGHT = 600;

static const int MAJOR_VERSION = 3;
static const int MINOR_VERSION = 3;

static const Uint32 WINDOW_FLAGS = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

void checkGLError(int line, const std::string& where)
{
  GLenum error = glGetError();
  if (error)
  {
    std::cout << "OpenGL error : " << error;
    std::cout << " , at line " << line << " in " << where << std::endl;
  }
}

int main(int argc, char *argv[])
{

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    std::cerr << "ERROR: SDL_Init() failed: ";
    std::cerr << SDL_GetError() << std::endl;

    return EXIT_FAILURE;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION);
  
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  
  SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, INIT_WINDOWX,
      INIT_WINDOWY, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT, WINDOW_FLAGS);

  if (window == NULL)
  {
    std::cerr << "ERROR: SDL_CreateWindow() failed: ";
    std::cerr << SDL_GetError() << std::endl;

    return EXIT_FAILURE;
  }

  SDL_GLContext context = SDL_GL_CreateContext(window);
  if (context == NULL)
  {
    std::cerr << "ERROR: SDL_GL_CreateContext() failed: ";
    std::cerr << SDL_GetError();
    std::cerr << "-- requested GL version: " << MAJOR_VERSION << "." << MINOR_VERSION << std::endl;
    return EXIT_FAILURE;
  }
  
  glewExperimental = GL_TRUE;
  GLenum error = glewInit();
  if (error != GLEW_OK)
  {
    std::cout << "ERROR: glewInit() failure : ";
    std::cout << glewGetErrorString(error) << std::endl;
    exit(EXIT_FAILURE);
  }
  checkGLError(__LINE__,"main()[glew bug]");
  
  init();
  resize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);

  SDL_Event window_event;
  Uint32 last_time = 0;
  Uint32 now_time;
  while (!quit_flag)
  {
    while (SDL_PollEvent(&window_event))
    {
      switch (window_event.type)
      {
        // window resize 
        case SDL_WINDOWEVENT:
          if (window_event.window.event == SDL_WINDOWEVENT_RESIZED)
          {
            resize(window_event.window.data1, window_event.window.data2);
          }
          break;
        case SDL_QUIT:
          quit_flag = true;
          break;
        default:
          event(&window_event);
          break;
      }

    }
    now_time = SDL_GetTicks();
    update(now_time - last_time);
    last_time = now_time;

    display();
    SDL_GL_SwapWindow(window);
  }
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
