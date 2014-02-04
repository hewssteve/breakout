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

Mesh* MeshComponent::getMesh(void) const
{
  return _mesh;
}
