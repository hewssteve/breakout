#include "MeshComponent.h"

MeshComponent::MeshComponent()
:
  _mesh(NULL)
{

}

MeshComponent::MeshComponent(Mesh* mesh)
:
  _mesh(mesh)
{

}

MeshComponent::~MeshComponent(){}

GLuint MeshComponent::getVAOID(void) const
{
  if(_mesh != NULL)
  {
    return _mesh->getVAO().getID();
  }
  else
  {
    return 0;
  }
}

Mesh* MeshComponent::getMesh(void) const
{
  return _mesh;
}
