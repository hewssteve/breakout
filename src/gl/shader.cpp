#include "breakout/gl/shader.h"

#include <cassert>

#include <glm/gtc/type_ptr.hpp>

namespace gl {

Shader::Shader() {
}

Shader::Shader(GLenum type, const std::string& source) {
  type_ = type;
  const GLchar* src = source.c_str();
  id_ = glCreateShaderProgramv(type, 1, &src);
  link_flag_ = true;
  if(!id_) {
    link_log_ = "ERROR: Could not create OpenGL shader object";
    link_flag_ = false;
  } else {
    if (source.empty()) {
      link_log_ = "ERORR: Shader source is empty.";
      link_flag_ = false;
    } else {
      GLint link_status;
      glGetProgramiv(id_, GL_LINK_STATUS, &link_status);
      if (link_status == GL_FALSE) {
        GLint info_log_len;
        glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &info_log_len);
        GLchar* info_log = new GLchar[info_log_len];
        glGetProgramInfoLog(id_, info_log_len, NULL, info_log);
        link_log_ = info_log;
        link_flag_ = false;
        delete info_log;
      }
    }
  }
  GL_CHECK_ERROR;
}

Shader::~Shader() {
  glDeleteProgram(id_);
  GL_CHECK_ERROR;
}

GLint Shader::getUniformLocation(const std::string& location_name) const {
  return glGetUniformLocation(id_, location_name.c_str());
}

void Shader::uniformMatrix4f(GLint location, const glm::mat4& mat) const {
  glProgramUniformMatrix4fv(id_, location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::uniformMatrix3f(GLint location, const glm::mat3& mat) const {
  glProgramUniformMatrix3fv(id_, location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::uniformMatrix2f(GLint location, const glm::mat2& mat) const {
  glProgramUniformMatrix2fv(id_, location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::uniform4f(GLint location, const glm::vec4& vec) const {
  glProgramUniform4fv(id_, location, 1, glm::value_ptr(vec));
}

void Shader::uniform3f(GLint location, const glm::vec3& vec) const {
  glProgramUniform3fv(id_, location, 1, glm::value_ptr(vec));
}

void Shader::uniform2f(GLint location, const glm::vec2& vec) const {
  glProgramUniform2fv(id_, location, 1, glm::value_ptr(vec));
}

void Shader::uniform1f(GLint location, float f) const {
  glProgramUniform1f(id_, location, f);
}

void Shader::uniform4i(GLint location, const glm::ivec4& vec) const {
  glProgramUniform4iv(id_, location, 1, glm::value_ptr(vec));
}

void Shader::uniform3i(GLint location, const glm::ivec3& vec) const {
  glProgramUniform3iv(id_, location, 1, glm::value_ptr(vec));
}

void Shader::uniform2i(GLint location, const glm::ivec2& vec) const {
  glProgramUniform2iv(id_, location, 1, glm::value_ptr(vec));
}

void Shader::uniform1i(GLint location, int i) const {
  glProgramUniform1f(id_, location, i);
}

}
