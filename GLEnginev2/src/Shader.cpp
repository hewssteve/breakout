#include "Shader.h"

Shader::Shader()
{
  _id = 0;
  _type = 0;
}

Shader::Shader(GLenum type)
{
  _id = 0;
  _type = type;
}

Shader::~Shader()
{

}

const GLchar* Shader::compile(const GLchar* source)
{
  GLchar* info_log;
  _id = glCreateShader(_type);
  glShaderSource(_id, 1, &source, NULL);
  glCompileShader(_id);

  GLint compile_status;
  glGetShaderiv(_id, GL_COMPILE_STATUS, &compile_status);
  if (compile_status == GL_FALSE)
  {
    GLint info_log_len;
    glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &info_log_len);
    info_log = new GLchar[info_log_len + 1];
    glGetShaderInfoLog(_id, info_log_len, NULL, info_log);
    return info_log;
  }
  return NULL;
}
