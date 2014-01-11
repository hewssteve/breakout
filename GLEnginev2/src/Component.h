#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

class Component
{
  private:

    std::string _entityID;

  public:

    Component(const std::string& entityID);
    virtual ~Component();

    const std::string& getEntityID() const
    {
      return _entityID;
    }

};

#endif /* COMPONENT_H_ */
