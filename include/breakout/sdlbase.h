#ifndef BREAKOUT_SDLBASE_H_
#define BREAKOUT_SDLBASE_H_

#include <SDL2/SDL.h>

bool init(void);

void render(float alpha);

void update(float t, float dt);

void cleanup(void);

void resize(int width, int height);

void window_event(SDL_Event* event);

void quit(void);

#endif // BREAKOUT_SDLBASE_H_
