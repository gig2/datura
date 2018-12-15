#include "transformation.h"

Transformation::Transformation( std::unique_ptr<Transformationimpl> ptr )
{
    impl_ = std::unique_ptr<Transformationimpl>( ptr.get() );
}

glm::mat4 Transformation::scale( glm::vec3 scale )
{
    return impl_.get()->scale( scale );
}

void Transformation::rotate( glm::vec3 axis, float angle )
{
    impl_.get()->rotate( axis, angle );
}

glm::mat4 Transformation::translate( glm::mat4 matrix, glm::vec3 direction )
{
    return impl_.get()->translate( matrix, direction );
}

void Transformation::lookAt( glm::vec3 position, glm::vec3 target, glm::vec3 up )
{
    impl_.get()->lookAt( position, target, up );
}

void Transformation::perspective( float fov, float aspect, float near, float far )
{
    impl_.get()->perspective( fov, aspect, near, far );
}

glm::vec4 Transformation::transformVector( glm::mat4 matrix, glm::vec4 vector )
{
    return impl_.get()->transformVector( matrix, vector );
}
