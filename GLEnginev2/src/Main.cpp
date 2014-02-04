#include "EngineMain.h"

#include <iostream>

int main(int argc, char *argv[])
{
  WindowManager window;

  if(!window.init(800,600,false))
  {
    std::cout << "Window failed to init." << std::endl;
    return -1;
  }

  EngineMain engine(&window);
  if(!engine.init())
  {
    std::cout << "Engine failed to init." << std::endl;
    return -1;
  }
  engine.mainLoop();

  return 0;
}
