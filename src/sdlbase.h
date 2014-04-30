
#ifndef SDLBASE_H_
#define SDLBASE_H_

#include <SDL2/SDL.h>
#define GLEW_STATIC
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>

bool init(void);

void render(float alpha);

void update(float t, float dt);

void cleanup(void);

void resize(int width, int height);

void window_event(SDL_Event* event);



#endif
