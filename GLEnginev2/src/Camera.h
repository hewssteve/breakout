#ifndef _CAMERA_H
#define _CAMERA_H

#include "SDLBase.h"

/******************************************************************************
 *
 *   Camera
 *
 *****************************************************************************/
class Camera
{

  public:

    Camera();
    Camera(const glm::vec3& position, const glm::vec3& look_dir,
        const glm::vec3& up_dir, float fov, float aspect, float far_plane,
        float near_plane);
    ~Camera();

    void translate(const glm::vec3& dir);
    void rotate(const glm::vec3& axis, float deg);

    float getFOV() const
    {
      return _fov;
    }

    void setFOV(float fov)
    {
      _fov = fov;
    }

    void addFOV(float fov)
    {
      if (_fov > 1.0f && fov < 180.0f)
      {
        _fov += fov;
      }
    }

    float getAspect() const
    {
      return _aspect;
    }

    void setAspect(float aspect)
    {
      _aspect = aspect;
    }

    float getNearPlane() const
    {
      return _near_plane;
    }

    void setNearPlane(float near_plane)
    {
      _near_plane = near_plane;
    }

    float getFarPlane() const
    {
      return _far_plane;
    }

    void setFarPlane(float far_plane)
    {
      _far_plane = far_plane;
    }

    const glm::vec3& getPosition() const
    {
      return _position;
    }

    void setPosition(const glm::vec3& position)
    {
      _position = position;
    }

    const glm::vec3& getLookDir() const
    {
      return _look_dir;
    }

    void setLookDir(const glm::vec3& lookdir)
    {
      _look_dir = lookdir;
    }

    glm::vec3 getUpDir() const
    {
      return _updir;
    }

    void setUpDir(const glm::vec3& updir)
    {
      _updir = updir;
    }

  private:

    glm::vec3 _position;
    glm::vec3 _look_dir;
    glm::vec3 _updir;

    float _fov;
    float _aspect;

    float _near_plane;
    float _far_plane;

};

#endif
