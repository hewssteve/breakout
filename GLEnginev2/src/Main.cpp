#include "EngineMain.h"

/*
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
*/
int main(int argc, char *argv[])
{
  EngineMain engine;
  if(!engine.init())
  {
    return -1;
  }
  engine.mainLoop();
  return 0;
}
