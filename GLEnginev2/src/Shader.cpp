#include "Shader.h"

Shader::Shader(shaderType type)
{
  GLenum gl_type;

  if (type == VERTEX)
  {
    gl_type = GL_VERTEX_SHADER;
  } else if (type == FRAGMENT)
  {
    gl_type = GL_FRAGMENT_SHADER;
  }

  m_id = glCreateShader(gl_type);
  m_compile_flag = false;
  m_type = type;
}

Shader::~Shader()
{
  glDeleteShader(m_id);
}

GLuint Shader::getID(void) const
{
  return m_id;
}

Shader::shaderType Shader::getType(void) const
{
  return m_type;
}

void Shader::loadSource(const GLchar* source)
{
  m_source = source;
  /*
   * TODO: get GLSL version from source
   *
   */

}

const std::string& Shader::getSource(void) const
{
  return m_source;
}

bool Shader::compile()
{
  glShaderSource(m_id, 1, m_source.c_str(), NULL);
  glCompileShader(m_id);

  GLint compile_status;
  glGetShaderiv(m_id, GL_COMPILE_STATUS, &compile_status);
  if (compile_status == GL_FALSE)
  {
    GLint info_log_len;
    glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &info_log_len);
    GLchar* info_log = new GLchar[info_log_len + 1];
    glGetShaderInfoLog(m_id, info_log_len, NULL, info_log);
    m_compile_log = info_log;
    delete info_log;
    return false;
  }
  m_compile_flag = true;
  return true;
}

bool Shader::isCompileOK(void) const
{
  return m_compile_flag;
}

const std::string& Shader::getCompileLog(void) const
{
  return m_compile_log;
}

const std::string& Shader::getGLSLversion(void) const
{
  return m_GLSL_version;
}

