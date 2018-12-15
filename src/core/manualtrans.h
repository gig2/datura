#ifndef MANUALTRANS_H
#define MANUALTRANS_H

#include "mode.h"
#include "quaternion.h"
#include "transformationimpl.h"

class Manualtrans : public TransformationImpl
{
public:
    Manualtrans() = default;

    glm::mat4 scale( glm::vec3 const& scale ) const override;
    Quaternion rotate( glm::vec3 const& axis, float angle ) const override;
    glm::mat4 translate( glm::vec3 const& direction ) const override;
    glm::mat4 lookAt( glm::vec3 const& position, glm::vec3 const& target,
                      glm::vec3 const& up ) const override;
    glm::mat4 perspective( float fov, float aspect, float near, float far ) const override;
    glm::vec4 transformVector( glm::mat4 const& matrix, glm::vec4 const& vector ) const override;
};

#endif // MANUALTRANS_H
