#ifndef SDL_BASE_H
#define SDL_BASE_H

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>


/******************************************************************************
 *
 *   Callback functions
 *   
 *   
 *
 *****************************************************************************/

void init();

void display();

void resize(int width, int height);

void update(int frame_time);

void cleanup();

void event(SDL_Event *event);

/******************************************************************************
 *
 *   Misc functions
 *
 *****************************************************************************/

void checkGLError(int line, const std::string& where);

#endif
