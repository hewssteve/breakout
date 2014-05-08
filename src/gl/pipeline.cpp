#include "breakout/gl/pipeline.h"

namespace gl {

Pipeline::Pipeline() {
  glGenProgramPipelines(1, &id_);
  GL_CHECK_ERROR;
}

Pipeline::~Pipeline() {
  glDeleteProgramPipelines(1, &id_);
  GL_CHECK_ERROR;
}

void Pipeline::useProgramStage(GLbitfield stage, GLuint shader) {
  glUseProgramStages(id_, stage, shader);
  GL_CHECK_ERROR;
}

}
