#ifndef _SHADERPROGRAM_H_
#define _SHADERPROGRAM_H_

#include <iostream>
#include <vector>
#include <gl/glew.h>

#include <glm/glm.hpp>


#include "Shader.h"

class ShaderProgram
{

  public:

    ShaderProgram();
    ~ShaderProgram();

    GLuint getID(void) const;

    bool link(const std::vector<Shader>& shaders);
    bool isLinkOK(void) const;

    const std::string& getLinkLog(void) const;

    GLint getUniformLocation(const std::string& location_name) const;

    void uniformMatrix4f(GLint location, const glm::mat4& mat) const;
    void uniformMatrix3f(GLint location, const glm::mat3& mat) const;
    void uniformMatrix2f(GLint location, const glm::mat2& mat) const;

    void uniform4f(GLint location, const glm::vec4& vec) const;
    void uniform3f(GLint location, const glm::vec3& vec) const;
    void uniform2f(GLint location, const glm::vec2& vec) const;
    void uniform1f(GLint location, float f) const;

  private:

    GLuint _id;
    bool _isLinked;

    std::string _link_log;

};

#endif
