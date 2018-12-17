#pragma once

#include <glm/matrix.hpp>
#include <glm/vec3.hpp>

class Quaternion
{
private:
    float x_;
    float y_;
    float z_;
    float w_;

public:
    Quaternion( float a, float b, float c, float d );
    Quaternion( glm::vec3 rotationAxis, float rotationAngle );
    float x() { return x_; }
    float y() { return y_; }
    float z() { return z_; }
    float w() { return w_; }

    glm::mat4 toMat4() const;
};
