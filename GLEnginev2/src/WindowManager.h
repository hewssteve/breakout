#ifndef _WINDOWMANAGER_H_
#define _WINDOWMANAGER_H_

#include <string>

class WindowManager
{

  public:

    WindowManager();
    WindowManager(int width, int height, bool fullscreen);
    virtual ~WindowManager();

    bool init(void);
    void setFullscreen(bool fullscreen);
    void setCaption(const std::string& caption);

    bool isFullscreen(void) const;

    int getWindowHeight(void) const;
    int getWindowWidth(void) const;

  private:

    int _window_height;
    int _window_width;

    bool _isFullscreen;

};

#endif
