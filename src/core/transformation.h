#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <memory>

#include "mode.h"
#include "transformationimpl.h"


class Transformation
{
private:
    std::unique_ptr<TransformationImpl> impl_;

public:
    Transformation( std::unique_ptr<TransformationImpl> transformationimpl );
    glm::mat4 scale( glm::vec3 scale );
    void rotate( glm::vec3 axis, float angle );
    glm::mat4 translate( glm::mat4 matrix, glm::vec3 direction );
    void lookAt( glm::vec3 position, glm::vec3 target, glm::vec3 up );
    void perspective( float fov, float aspect, float near, float far );
    glm::vec4 transformVector( glm::mat4 matrix, glm::vec4 vector );
};

#endif // TRANSFORMATION_H
