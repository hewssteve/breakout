#include "Camera.h"

Camera::Camera() {

}
Camera::Camera(const glm::vec3& position, const glm::vec3& look_dir,
    const glm::vec3& up_dir, float fov, float aspect, float far_plane,
    float near_plane) {
  setPosition(position);
  setLookDir(look_dir);
  setUpDir(up_dir);
  setFOV(fov);
  setAspect(aspect);
  setFarPlane(far_plane);
  setNearPlane(near_plane);
}

Camera::~Camera() {
}

void Camera::translate(const glm::vec3& dir) {
  _position += dir;
}

void Camera::rotate(const glm::vec3& axis, float deg) {

}
