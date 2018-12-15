#include "transformation.h"

Transformation::Transformation( Mode const& mode )
    : impl_{createTransformation( mode )}
{
}

glm::mat4 Transformation::scale( glm::vec3 const& scale ) const
{
    return impl_->scale( scale );
}

Quaternion Transformation::rotate( glm::vec3 const& axis, float angle ) const
{
    return impl_->rotate( axis, angle );
}

glm::mat4 Transformation::translate( glm::vec3 const& direction ) const
{
    return impl_->translate( direction );
}

glm::mat4 Transformation::lookAt( glm::vec3 const& position, glm::vec3 const& target,
                                  glm::vec3 const& up ) const
{
    return impl_->lookAt( position, target, up );
}

glm::mat4 Transformation::perspective( float fov, float aspect, float near, float far ) const
{
    return impl_->perspective( fov, aspect, near, far );
}

glm::vec4 Transformation::transformVector( glm::mat4 const& matrix, glm::vec4 const& vector ) const
{
    return impl_->transformVector( matrix, vector );
}
