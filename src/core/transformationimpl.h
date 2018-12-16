#ifndef TRANSFORMATIONIMPL_H
#define TRANSFORMATIONIMPL_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include "mode.h"
#include "quaternion.h"

class TransformationImpl
{
public:
    virtual ~TransformationImpl();
    virtual glm::mat4 scale( glm::vec3 const& scale ) const                                     = 0;
    virtual Quaternion rotate( glm::vec3 const& axis, float angle ) const                       = 0;
    virtual glm::mat4 translate( glm::vec3 const& direction ) const                             = 0;
    virtual glm::mat4 lookAt( glm::vec3 const& position, glm::vec3 const& target,
                              glm::vec3 const& up ) const                                       = 0;
    virtual glm::mat4 perspective( float fov, float aspect, float near, float far ) const       = 0;
    virtual glm::vec4 transformVector( glm::mat4 const& matrix, glm::vec4 const& vector ) const = 0;
};

#endif // TRANSFORMATIONIMPL_H
