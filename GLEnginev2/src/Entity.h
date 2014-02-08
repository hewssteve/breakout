#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{

  public:

    static unsigned MAX_COMPONENTS;
    static int NO_COMPONENT;

    enum CompType
    {
      POSITION = 0,
      MOVEMENT,
      MESH
    };

    Entity();
    virtual ~Entity();

    int getHandle(void);
    int getCompHandle(CompType type);

  private:

    int _handle;
    int _comp_handles[10];

};

#endif
