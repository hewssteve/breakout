#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>

class Camera
{

  public:

    Camera();
    Camera(const glm::vec3& position, const glm::vec3& look_dir,
        const glm::vec3& up_dir, float fov, float aspect, float far_plane,
        float near_plane);
    virtual ~Camera();

    float getFOV(void) const;
    float getAspect(void) const;
    float getNearPlane(void) const;
    float getFarPlane(void) const;

    const glm::vec3& getPosition(void) const;
    const glm::vec3& getLookDir(void) const;
    const glm::vec3& getUpDir(void) const;

    void setFOV(float fov);
    void setAspect(float aspect);
    void setNearPlane(float near_plane);
    void setFarPlane(float far_plane);
    void setPosition(const glm::vec3& position);
    void setLookDir(const glm::vec3& lookdir);
    void setUpDir(const glm::vec3& updir);

    void translate(const glm::vec3& dir);
    void rotate(const glm::vec3& axis, float deg);

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
