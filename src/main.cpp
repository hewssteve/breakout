
#include <SDL2/SDL.h>

#include "breakout/util.h"
#include "breakout/windowmanager.h"
#include "breakout/engine.h"

void cleanup(void)
{
   SDL_Quit();
}

int main(int argc, char *argv[])
{
  const std::string CAPTION = "WINDOW TITLE";
  const Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
  const int WIDTH = 500;
  const int HEIGHT = 500;
  
  const Uint32 SDL_FLAGS = SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS;
  if (SDL_Init(SDL_FLAGS) > 0) return EXIT_FAILURE;
  
  Engine engine;
  WindowManager main_window;
  if (!main_window.init(CAPTION, WINDOW_FLAGS, WIDTH, HEIGHT, false))
  {
    cleanup();
    return EXIT_FAILURE;
  }
  if(!engine.init(&main_window))
  {
    cleanup();
    return EXIT_FAILURE;
  }
  
  engine.mainLoop();
  
  cleanup();
  return EXIT_SUCCESS;
}
