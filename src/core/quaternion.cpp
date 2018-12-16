#include "quaternion.h"

#include <cmath>

Quaternion::Quaternion( float x, float y, float z, float w )
{
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
}

// Note : rotationAngle must be in radian
// Source : http://www.opengl-tutorial.org/fr/intermediate-tutorials/tutorial-17-quaternions/
Quaternion::Quaternion( glm::vec3 rotationAxis, float rotationAngle )
{
    x_ = rotationAxis.x * std::sin( rotationAngle / 2 );
    y_ = rotationAxis.y * std::sin( rotationAngle / 2 );
    z_ = rotationAxis.z * std::sin( rotationAngle / 2 );
    w_ = std::cos( rotationAngle / 2 );
}

glm::mat4 Quaternion::toMat4() const
{
    glm::mat4 out{0.f};

    const float a2 = x_ * x_;
    const float b2 = y_ * y_;
    const float c2 = z_ * z_;
    const float d2 = w_ * w_;

    const float twiceAb = 2.f * x_ * y_;
    const float twiceAc = 2.f * x_ * z_;
    const float twiceAd = 2.f * x_ * w_;

    const float twiceBc = 2.f * y_ * z_;
    const float twiceBd = 2.f * y_ * w_;

    const float twiceCd = 2.f * z_ * w_;

    out[ 0 ][ 0 ] = a2 + b2 - c2 - d2;
    out[ 0 ][ 1 ] = twiceBc + twiceAd;
    out[ 0 ][ 2 ] = twiceBd - twiceAc;


    out[ 1 ][ 0 ] = twiceBc - twiceAd;
    out[ 1 ][ 1 ] = a2 - b2 + c2 - d2;
    out[ 1 ][ 2 ] = twiceCd + twiceAb;

    out[ 2 ][ 0 ] = twiceBd + twiceAc;
    out[ 2 ][ 1 ] = twiceCd - twiceAb;
    out[ 2 ][ 2 ] = a2 - b2 - c2 + d2;

    out[ 3 ][ 0 ] = 0.f;
    out[ 3 ][ 1 ] = 0.f;
    out[ 3 ][ 2 ] = 0.f;
    out[ 3 ][ 3 ] = 1.f;


    return out;
}
