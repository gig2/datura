#include "autotrans.h"
#include <glm/gtc/quaternion.hpp>

glm::mat4 AutoTransformation::scale( glm::vec3 const& scale ) const
{
    //
    return glm::scale( glm::mat4{1.f}, scale );
}
Quaternion AutoTransformation::rotate( glm::vec3 const& axis, float angle ) const
{
    auto orient = glm::angleAxis( angle, axis );

    return Quaternion{orient.x, orient.y, orient.z, orient.w};
}

glm::mat4 AutoTransformation::translate( glm::vec3 const& direction ) const
{
    return glm::translate( glm::mat4{1.f}, direction );
}

glm::mat4 AutoTransformation::lookAt( glm::vec3 const& position, glm::vec3 const& target,
                                      glm::vec3 const& up ) const
{
    return glm::lookAt( position, target, up );
}

glm::mat4 AutoTransformation::perspective( float fov, float aspect, float near, float far ) const
{
    return glm::perspective( fov, aspect, near, far );
}
glm::vec4 AutoTransformation::transformVector( glm::mat4 const& matrix,
                                               glm::vec4 const& vector ) const
{
    return matrix * vector;
}
