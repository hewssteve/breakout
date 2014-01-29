#ifndef _COMPONENTSYSTEM_H_
#define _COMPONENTSYSTEM_H_

class ComponentSystem
{

  public:

    ComponentSystem();

    virtual ~ComponentSystem();

    virtual void init(void) = 0;

    virtual void update(float time, float dt, float alpha) = 0;

};

#endif
