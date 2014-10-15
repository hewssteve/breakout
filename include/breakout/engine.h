#ifndef BREAKOUT_ENGINE_H
#define	BREAKOUT_ENGINE_H

#include "breakout/util.h"
#include "windowmanager.h"

class Engine
{
  
public:
  Engine();
  virtual ~Engine();
  
  bool init(WindowManager* window);
  
  void mainLoop(void);
  
  void update(float t, float dt);
  void render(void);
  
private:
  
  WindowManager* _window;
  
  DISALLOW_COPY_AND_ASSIGN(Engine);
};


#endif	/* ENGINE_H */

