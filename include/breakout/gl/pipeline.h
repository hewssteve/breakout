#ifndef GL_PIPELINE_H_
#define GL_PIPELINE_H_

#include "breakout/util.h"

namespace gl {

class Pipeline {
  public:
    Pipeline();
    virtual ~Pipeline();

    void useProgramStage(GLbitfield stage, GLuint shader);

    GLuint id(void) const {
      return id_;
    }

  private:
    GLuint id_;

    DISALLOW_COPY_AND_ASSIGN(Pipeline);
};

}

#endif // GL_PIPELINE_H_
