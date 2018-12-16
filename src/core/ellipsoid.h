#pragma once

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "mode.h"
#include "quaternion.h"
#include "nuage.h"

class Ellipsoid
{
public:
    explicit Ellipsoid( Mode const& mode );
    Nuage createCloud(int n, float dmin);
    Distance createDistance(glm::vec3 scale);

private:
    Mode const mode_;
    glm::vec3 scale_;
    glm::vec3 center_;
    Quaternion orientation_;
    Nuage cloud_;
};
