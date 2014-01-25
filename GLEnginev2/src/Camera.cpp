#include "Camera.h"

Camera::Camera(){}

Camera::Camera(const glm::vec3& position, const glm::vec3& look_dir,
    const glm::vec3& up_dir, float fov, float aspect, float far_plane,
    float near_plane)
:
    _position(position),
    _look_dir(look_dir),
    _updir(up_dir),
    _fov(fov),
    _aspect(aspect),
    _near_plane(near_plane),
    _far_plane(far_plane)
{
}

Camera::~Camera(){}

float Camera::getFOV(void) const
{
  return _fov;
}

float Camera::getAspect(void) const
{
  return _aspect;
}

float Camera::getNearPlane(void) const
{
  return _near_plane;
}

float Camera::getFarPlane(void) const
{
  return _far_plane;
}

const glm::vec3& Camera::getPosition(void) const
{
  return _position;
}

const glm::vec3& Camera::getLookDir(void) const
{
  return _look_dir;
}

const glm::vec3& Camera::getUpDir(void) const
{
  return _updir;
}

void Camera::setFOV(float fov)
{
  _fov = fov;
}

void Camera::setAspect(float aspect)
{
  _aspect = aspect;
}

void Camera::setNearPlane(float near_plane)
{
  _near_plane = near_plane;
}

void Camera::setFarPlane(float far_plane)
{
  _far_plane = far_plane;
}

void Camera::setPosition(const glm::vec3& position)
{
  _position = position;
}

void Camera::setLookDir(const glm::vec3& lookdir)
{
  _look_dir = lookdir;
}

void Camera::setUpDir(const glm::vec3& updir)
{
  _updir = updir;
}

void Camera::translate(const glm::vec3& dir)
{
  _position += dir;
}

void Camera::rotate(const glm::vec3& axis, float deg)
{

}
