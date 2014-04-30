#ifndef GL_SHADER_H_
#define GL_SHADER_H_

#include "util.h"

namespace gl {

class Shader {
  public:
    Shader();
    Shader(GLenum type, const std::string& source);
    virtual ~Shader();

    GLint getUniformLocation(const std::string& location_name) const;
    void uniformMatrix4f(GLint location, const glm::mat4& mat) const;
    void uniformMatrix3f(GLint location, const glm::mat3& mat) const;
    void uniformMatrix2f(GLint location, const glm::mat2& mat) const;
    void uniform4f(GLint location, const glm::vec4& vec) const;
    void uniform3f(GLint location, const glm::vec3& vec) const;
    void uniform2f(GLint location, const glm::vec2& vec) const;
    void uniform1f(GLint location, float f) const;
    void uniform4i(GLint location, const glm::ivec4& vec) const;
    void uniform3i(GLint location, const glm::ivec3& vec) const;
    void uniform2i(GLint location, const glm::ivec2& vec) const;
    void uniform1i(GLint location, int i) const;

    GLuint id(void) const {
      return id_;
    }
    GLenum type(void) const {
      return type_;
    }
    bool link_flag(void) const {
      return link_flag_;
    }
    const std::string& link_log(void) const {
      return link_log_;
    }

  private:
    GLuint id_;
    GLenum type_;
    bool link_flag_;
    std::string link_log_;

    DISALLOW_COPY_AND_ASSIGN(Shader);
};

}
#endif // BREAKOUT_GL_SHADER_H_
