
#include "RenderSystem.h"

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::init(void)
{
  std::vector<Shader> shaders;

  Shader v_shader(Shader::VERTEX);
  Shader f_shader(Shader::FRAGMENT);

  std::string v_shader_source_loc = "shaders/shader.vert";
  std::string f_shader_source_loc = "shaders/shader.frag";
  
  std::string v_shader_source = getShaderSource(v_shader_source_loc);
  std::string f_shader_source = getShaderSource(f_shader_source_loc);

  //compileShader(&v_shader, v_shader_source);
  //compileShader(&f_shader, f_shader_source);

  shaders.push_back(v_shader);
  shaders.push_back(f_shader);

  if(!_shaderprogram.link(shaders))
  {
    // shader program link error
  }
  
}

void RenderSystem::update(float dt)
{
  
  
  
  
}

