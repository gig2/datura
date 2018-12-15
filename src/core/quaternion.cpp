#include "quaternion.h"

#include <cmath>

Quaternion::Quaternion(float x, float y, float z, float w){
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
}

//Note : rotationAngle must be in radian
//Source : http://www.opengl-tutorial.org/fr/intermediate-tutorials/tutorial-17-quaternions/
Quaternion::Quaternion(glm::vec3 rotationAxis, float rotationAngle){
    x_ = rotationAxis.x * std::sin(rotationAngle / 2);
    y_ = rotationAxis.y * std::sin(rotationAngle / 2);
    z_ = rotationAxis.z * std::sin(rotationAngle / 2);
    w_ = std::cos(rotationAngle / 2);
}
