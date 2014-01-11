#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
  _id = glCreateProgram();
  _isLinked = false;
}

GLuint ShaderProgram::getID() const
{
  return _id;
}



bool ShaderProgram::link(const std::vector<Shader>& shaders) {

  std::vector<Shader>::const_iterator i;
  for (i = shaders.begin(); i != shaders.end(); i++) {
    glAttachShader(_id, i->getID());
  }
  glLinkProgram(_id);

  GLint link_status;
  glGetProgramiv(_id, GL_LINK_STATUS, &link_status);

  if (link_status == GL_FALSE) {

    GLint info_log_len;
    glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &info_log_len);

    GLchar* info_log = new GLchar[info_log_len + 1];
    glGetProgramInfoLog(_id, info_log_len, NULL, info_log);
    _link_log = info_log;
    delete info_log;
    return info_log;
  }
  _isLinked = true;
  return true;
}

bool ShaderProgram::isLinkOK(void) const
{
  return _isLinked;
}

const std::string& ShaderProgram::getLinkLog(void) const
{
  return _link_log;
}

GLuint ShaderProgram::getUniformLocation(const char* location_name) const {
  return glGetUniformLocation(_id, location_name);
}

void ShaderProgram::uniformMatrix4f(GLuint location,
    const glm::mat4& mat) const {
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::uniformMatrix3f(GLuint location,
    const glm::mat3& mat) const {
  glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::uniformMatrix2f(GLuint location,
    const glm::mat2& mat) const {
  glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::uniform4f(GLuint location, const glm::vec4& vec) const {
  glUniform4fv(location, 1, glm::value_ptr(vec));
}

void ShaderProgram::uniform3f(GLuint location, const glm::vec3& vec) const {
  glUniform3fv(location, 1, glm::value_ptr(vec));
}

void ShaderProgram::uniform2f(GLuint location, const glm::vec2& vec) const {
  glUniform2fv(location, 1, glm::value_ptr(vec));
}

void ShaderProgram::uniform1f(GLuint location, float f) const {
  glUniform1f(location, f);
}

ShaderProgram::~ShaderProgram() {
  glDeleteProgram(_id);
}

