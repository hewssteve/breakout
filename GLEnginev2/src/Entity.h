
#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
    
  public:
    Entity();
    virtual ~Entity();
    
  private:
    
    unsigned _handle;
    unsigned _components[10];
    
};

#endif
