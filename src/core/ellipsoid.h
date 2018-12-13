#pragma once

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "mode.h"
#include "quaternion.h"

class Ellipsoid
{
public:
    explicit Ellipsoid( Mode const& mode );




private:
    Mode const mode_;
    glm::vec3 scale_;
    glm::vec3 center_;
    Quaternion orientation_;
};
