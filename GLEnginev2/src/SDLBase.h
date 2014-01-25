#ifndef _SDL_BASE_H_
#define _SDL_BASE_H_

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>

void init();

void display();

void resize(int width, int height);

void update(int frame_time);

void cleanup();

void event(const SDL_Event& event);

void checkGLError(int line, const std::string& where);

#endif
