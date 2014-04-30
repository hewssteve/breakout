
#include "sdlbase.h"
#include "util.h"

#define FIXED_TIMESTEP 0

int main(int argc, char *argv[]) {

  SDL_Window* sdl_window;
  SDL_GLContext gl_context;

  const std::string caption = "Breakout";

  const Uint32 window_flags = SDL_WINDOW_OPENGL;
  const Uint32 sdl_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS;

  const int MAJOR_VERSION = 4;
  const int MINOR_VERSION = 1;

  const int WIDTH = 512 * 1.5;
  const int HEIGHT = 512 * 1.5;

  if (SDL_Init(sdl_flags) > 0) {
    return EXIT_FAILURE;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  sdl_window = SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, window_flags);
  if (sdl_window == NULL) {
    return EXIT_FAILURE;
  }

  gl_context = SDL_GL_CreateContext(sdl_window);

  glewExperimental = GL_TRUE;
  GLenum error = glewInit();
  if (error != GLEW_OK) {
    return EXIT_FAILURE;
  }
  GL_CHECK_ERROR;
  if(!init()) {
    std::cout << "init failed, exiting..." << std::endl;
    return EXIT_FAILURE;
  }
  resize(WIDTH, HEIGHT);

  // main loop
  bool quit = false;
  Uint32 current_time = SDL_GetTicks();
  float t = 0.0f;
#if FIXED_TIMESTEP
  float accumulator = 0.0f;
  const float DT = 0.05f;
  const float MAX_FRAME_DT = 0.25f;
#endif
  while (!quit) {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_WINDOWEVENT:
          if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
            resize(event.window.data1, event.window.data2);
          }
          break;
        case SDL_QUIT:
          quit = true;
          break;
        default:
          window_event(&event);
          break;
      };
    }
    const Uint32 new_time = SDL_GetTicks();
    float frame_time = (new_time - current_time) * 0.001f;
    current_time = new_time;
#if FIXED_TIMESTEP
    if (frame_time > MAX_FRAME_DT) {
      frame_time = MAX_FRAME_DT;
    }
    accumulator += frame_time;

    while (accumulator >= DT) {
      accumulator -= DT;
      update(t, DT);
      t += DT;
    }

    const double alpha = accumulator / DT;
    render(alpha);
#else
    t += frame_time;
    update(t, frame_time);
    render(0);
#endif
    SDL_GL_SwapWindow(sdl_window);
  }
  cleanup();
  return EXIT_SUCCESS;
}
