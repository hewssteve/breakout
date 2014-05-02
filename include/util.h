
#ifndef UTIL_H_
#define UTIL_H_

#include "sdlbase.h"

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

struct vertex {
    vertex() {}
    vertex(const glm::vec2 pos): position(pos) {}
    glm::vec2 position;
};

std::string string_from_file(const std::string& filename);

#define GL_CHECK_ERROR gl_checkError(__LINE__, __FILE__)

void gl_checkError(int line, const std::string& where);

#endif
