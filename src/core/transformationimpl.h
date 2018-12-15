#ifndef TRANSFORMATIONIMPL_H
#define TRANSFORMATIONIMPL_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include "mode.h"

class transformationimpl
{
public:
    virtual ~transformationimpl();
    virtual glm::mat4 scale(glm::vec3 scale) = 0;
    virtual void rotate(glm::vec3 axis, float angle) = 0;
    virtual glm::mat4 translate(glm::mat4 matrix, glm::vec3 direction) = 0;
    virtual void lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up) = 0;
    virtual void perspective(float fov, float aspect, float near, float far) = 0;
    virtual glm::vec4 transformVector(glm::mat4 matrix, glm::vec4 vector) = 0;
};

#endif // TRANSFORMATIONIMPL_H
