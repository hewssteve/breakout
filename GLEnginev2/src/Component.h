#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>

class Component
{

  public:

    Component(const std::string& entityID);
    virtual ~Component();

    const std::string& getEntityID(void) const;

  private:

    std::string _entityID;

};

#endif
