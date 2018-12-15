#include "manualtrans.h"
#include "quaternion.h"

#include <stdexcept>


// Build Scale Matrix.
glm::mat4 Manualtrans::scale( glm::vec3 const& scale ) const
{
    glm::mat4 matrix_to_return = glm::mat4{0.f};
    for ( int i = 0; i < 3; i++ )
    {
        matrix_to_return[ i ][ i ] = scale[ i ];
    }
    matrix_to_return[ 3 ][ 3 ] = 1;
    return matrix_to_return;
}

Quaternion Manualtrans::rotate( glm::vec3 const& axis, float angle ) const
{
    return Quaternion{axis, angle};
}

// Build Translate Matrix.
glm::mat4 Manualtrans::translate( glm::vec3 const& direction ) const
{
    glm::mat4 matrix_to_return{0.f};
    for ( int i = 0; i < 4; i++ )
    {
        matrix_to_return[ i ][ i ] = 1;
    }
    for ( int i = 0; i < 3; i++ )
    {
        matrix_to_return[ 3 ][ i ] = direction[ i ];
    }
    return matrix_to_return;
}

glm::mat4 Manualtrans::lookAt( glm::vec3 const& position, glm::vec3 const& target,
                               glm::vec3 const& up ) const
{
    throw std::runtime_error( "Look at manual is not implemented" );
}

glm::mat4 Manualtrans::perspective( float fov, float aspect, float near, float far ) const
{
    throw std::runtime_error( "perspective at manual is not implemented" );
}

// Return modified parameter vector thanks to a multiplication
// between given two parameters.
glm::vec4 Manualtrans::transformVector( glm::mat4 const& matrix, glm::vec4 const& vector ) const
{
    glm::vec4 vector_to_return;
    for ( int i = 0; i < 4; i++ )
    {
        float res = 0.f;
        for ( int j = 0; j < 4; j++ )
        {
            res += vector[ j ] * matrix[ j ][ i ];
        }
        vector_to_return[ i ] = res;
    }
    return vector_to_return;
}
