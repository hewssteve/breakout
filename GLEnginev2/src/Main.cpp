#include <vector>
#include <map>
#include <iterator>

#include "SDLBase.h"

#include "ShaderProgram.h"
#include "Shader.h"
#include "Tokenizer.h"
#include "MeshComponent.h"

bool compileShader(Shader& shader, const std::string& source)
{
  std::cout << "==============================" << std::endl;
  std::cout << "Shader source: " << std::endl;
  std::cout << source << std::endl;
  
  shader.loadSource(source.c_str());

  if (!shader.compile())
  {
    std::cout << "=======================================" << std::endl;
    std::cout << "Shader compile error: (" << shader.getID() << ")"
        << std::endl;
    std::cout << shader.getCompileLog() << std::endl;
    std::cout << "=======================================" << std::endl;
    return false;
  }
  return true;
}

/* ----------------------------- Callbacks --------------------------------- */

void init()
{
  std::string terrain_file_loc = "models/terrain.obj";
 
  VertexAttribute position  = {4, GL_FLOAT, GL_FALSE, 0};
  VertexAttribute normal    = {3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3)};
  VertexAttribute tex_coord = {2, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec3)};
  
  AttributeSet attrs;
  attrs.insert(AttrPair(0, position));
  attrs.insert(AttrPair(1, normal));
  attrs.insert(AttrPair(2, tex_coord));
  
  glEnable(GL_DEPTH_TEST);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void resize(int width, int height)
{
  glViewport(0, 0, width, height);

  //proj = glm::perspective(75.0f, (float) width / height, 0.01f, 2000.0f);

}

void update(int frame_time)
{
  //float dt = frame_time * 0.001f;

}

void cleanup()
{

}

void keyDown(SDL_Keycode key)
{
  switch (key)
  {
    default:
      break;
  }
}

void keyUp(SDL_Keycode key)
{
  switch (key)
  {
    default:
      break;
  }
}

void event(const SDL_Event& event)
{
  switch (event.type)
  {
    case SDL_KEYDOWN:
      keyDown(event.key.keysym.sym);
      break;
    case SDL_KEYUP:
      keyUp(event.key.keysym.sym);
      break;
    default:
      break;
  }
}
