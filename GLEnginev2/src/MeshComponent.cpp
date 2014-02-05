#include <cassert>

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
  assert(_mesh != NULL);
  return _mesh;
}
