#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <memory>

#include "mode.h"
#include "quaternion.h"
#include "transformationimpl.h"


class Transformation
{
private:
    std::unique_ptr<TransformationImpl> const impl_;

public:
    explicit Transformation( Mode const& mode );
    glm::mat4 scale( glm::vec3 const& scale ) const;
    Quaternion rotate( glm::vec3 const& axis, float angle ) const;
    glm::mat4 translate( glm::vec3 const& direction ) const;
    glm::mat4 lookAt( glm::vec3 const& position, glm::vec3 const& target,
                      glm::vec3 const& up ) const;
    glm::mat4 perspective( float fov, float aspect, float near, float far ) const;
    glm::vec4 transformVector( glm::mat4 const& matrix, glm::vec4 const& vector ) const;
};

#endif // TRANSFORMATION_H
