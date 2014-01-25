#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{

  public:

    Entity();
    virtual ~Entity();

    const std::string& getID(void) const;

    static const unsigned MAX_COMPONENTS;

  private:

    std::string _id;
    unsigned _handle;
    unsigned _components[MAX_COMPONENTS];

};

#endif
