
#include "util.h"

#include <fstream>

bool compile_shader(GLuint* shader, GLenum type, std::string source) {
  const GLchar* src = source.c_str();
  *shader = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &src);
  GL_CHECK_ERROR;
  GLint link_status;
  glGetProgramiv(*shader, GL_LINK_STATUS, &link_status);
  if (link_status == GL_FALSE) {
    GLint info_log_len;
    glGetProgramiv(*shader, GL_INFO_LOG_LENGTH, &info_log_len);
    GLchar* info_log = new GLchar[info_log_len];
    glGetProgramInfoLog(*shader, info_log_len, NULL, info_log);
    std::string log = info_log;
    std::cout << log << std::endl;
    delete info_log;
    return false;
  }
  return true;
}

std::string string_from_file(const std::string& filename) {
  std::ifstream in(filename.c_str(), std::ios::in);
  if (!in.is_open()) {
    std::cout << "unable to open \'" << filename << "\'." << std::endl;
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
    std::cout << "OpenGL error : " << errorstr;
    std::cout << "  at line " << line << " in " << where << std::endl;
  }
}
