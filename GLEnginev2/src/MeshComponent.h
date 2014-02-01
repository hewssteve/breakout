#ifndef _MESHCOMPONENT_H_
#define _MESHCOMPONENT_H_

#include <gl/glew.h>

#include "Component.h"
#include "Mesh.h"

class MeshComponent : public Component
{

  public:

    MeshComponent();
    MeshComponent(Mesh* mesh);
    virtual ~MeshComponent();

    GLuint getVAOID(void) const;
    Mesh* getMesh(void) const;


  private:

    Mesh* _mesh;


};

#endif
