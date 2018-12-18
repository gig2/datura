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
    return Quaternion{glm::normalize( axis ), angle};
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

// Defines a view matrix, transform from world space to position space.
// Source : https://stackoverflow.com/questions/21830340/understanding-glmlookat
glm::mat4 Manualtrans::lookAt( glm::vec3 const& position, glm::vec3 const& target,
                               glm::vec3 const& up ) const
{
    glm::mat4 matrix_to_return{1.f};
    glm::vec3 X, Y, Z;

    // New coordinate system, X points to the left, Y up and Z forward.
    Z = position - target; // line of sight
    // Get a vector with the same direction as Z but with norm of 1.
    Z = glm::normalize( Z );
    Y = glm::normalize( up );
    X = glm::cross( Y, Z );
    X = glm::normalize( X );

    // Cross product of Z and X, that is to say get the vector which
    // is perdendicular to Z and X.
    Y = glm::cross( Z, X );

    matrix_to_return[ 0 ][ 0 ] = X.x;
    matrix_to_return[ 1 ][ 0 ] = X.y;
    matrix_to_return[ 2 ][ 0 ] = X.z;
    // Dot product of X and position, that is to say X * position.
    matrix_to_return[ 3 ][ 0 ] = -glm::dot( X, position );
    matrix_to_return[ 0 ][ 1 ] = Y.x;
    matrix_to_return[ 1 ][ 1 ] = Y.y;
    matrix_to_return[ 2 ][ 1 ] = Y.z;
    matrix_to_return[ 3 ][ 1 ] = -glm::dot( Y, position );
    matrix_to_return[ 0 ][ 2 ] = Z.x;
    matrix_to_return[ 1 ][ 2 ] = Z.y;
    matrix_to_return[ 2 ][ 2 ] = Z.z;
    matrix_to_return[ 3 ][ 2 ] = -glm::dot( Z, position );
    matrix_to_return[ 0 ][ 3 ] = 0;
    matrix_to_return[ 1 ][ 3 ] = 0;
    matrix_to_return[ 2 ][ 3 ] = 0;
    matrix_to_return[ 3 ][ 3 ] = 1.0f;

    return matrix_to_return;
}

// Set the perspective projection matrix.
// fov -> field of view
// aspect -> generally equal to (window width / window height)
// near parameter represents distance of the view plane which is closer to the camera.
// far parameter represents distance of the view plane which is far from the camera.
// Source : https://github.com/g-truc/glm/blob/0.9.5/glm/gtc/matrix_transform.inl#L208
glm::mat4 Manualtrans::perspective( float fov, float aspect, float near, float far ) const
{
    glm::mat4 matrix_to_return = glm::mat4{1.f};

    float rad           = fov;
    float cotanHalfFovy = 1 / std::tan( rad / 2 );

    matrix_to_return[ 0 ][ 0 ] = cotanHalfFovy / aspect;
    matrix_to_return[ 1 ][ 1 ] = cotanHalfFovy;
    matrix_to_return[ 2 ][ 2 ] = ( far + near ) / ( far - near );
    matrix_to_return[ 2 ][ 3 ] = -1;
    matrix_to_return[ 3 ][ 2 ] = -( 2 * far * near ) / ( far - near );

    return matrix_to_return;
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
