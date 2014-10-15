#ifndef WINDOWMANAGER_H
#define	WINDOWMANAGER_H

#include <SDL2/SDL.h>

#include "breakout/util.h"

class WindowManager 
{
  
public:
  WindowManager();
  virtual ~WindowManager();
  
  bool init(const std::string& caption, Uint32 window_flags, int width, int height,
        bool fullscreen);
  
  void setCaption(const std::string& caption);
  void setFullscreen(bool fullscreen);
  
  bool pollEventQueue(SDL_Event* e);
  Uint32 getTime(void);
  
private:
  
  SDL_Window* _window;

  DISALLOW_COPY_AND_ASSIGN(WindowManager);
};

#endif	/* WINDOWMANAGER_H */

