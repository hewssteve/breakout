#ifndef SHADER_H
#define SHADER_H

#include <string>

#include "SDLBase.h"

class Shader {
  public:

    enum shaderType {
      VERTEX, FRAGMENT
    };

    Shader(shaderType type);
    virtual ~Shader();

    GLuint getID(void) const;

    shaderType getType(void) const;

    void loadSource(const GLchar* source);

    const std::string& getSource(void) const;

    bool compile(void);

    bool isCompileOK(void) const;

    const std::string& getCompileLog(void) const;

    const std::string& getGLSLversion(void) const;

  private:

    GLuint m_id;
    shaderType m_type;

    bool m_compile_flag;

    std::string m_GLSL_version;
    std::string m_compile_log;
    std::string m_source;

};

#endif
