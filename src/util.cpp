#include "breakout/util.h"

#include <fstream>
// TODO manage errors more meaningfully
std::string string_from_file(const std::string& filename) {
  std::ifstream in(filename.c_str(), std::ios::in);
  if (!in.is_open()) {
    fprintf(stderr, "unable to open '%s'\n", filename.c_str());
    return "";
  }
  std::string contents;
  in.seekg(0, std::ios::end);
  int length = in.tellg();
  contents.resize(length);
  in.seekg(0, std::ios::beg);
  in.read(&contents[0], contents.size());
  return contents;
}

void gl_checkError(int line, const std::string& where) {
  GLenum error;
  // there may be serveral error flags
  // so we loop until all error flags are reset
  while ((error = glGetError()) != GL_NO_ERROR) {
    std::string errorstr;
    switch (error) {
      case GL_INVALID_ENUM:
        errorstr = "INVALID ENUM";
        break;
      case GL_INVALID_VALUE:
        errorstr = "INVALID VALUE";
        break;
      case GL_INVALID_OPERATION:
        errorstr = "INVALID OPERATION";
        break;
      case GL_INVALID_FRAMEBUFFER_OPERATION:
        errorstr = "INVALID FRAMEBUFFER OPERATION";
        break;
      case GL_OUT_OF_MEMORY:
        errorstr = "OUT OF MEMORY";
        break;
      case GL_STACK_UNDERFLOW:
        errorstr = "STACK UNDERFLOW";
        break;
      case GL_STACK_OVERFLOW:
        errorstr = "STACK OVERFLOW";
        break;
    };
    fprintf(stderr, "OpenGL error: %s at line %d in %s\n", errorstr.c_str(), line, where.c_str());
  }
}
