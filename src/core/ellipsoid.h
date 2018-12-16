#pragma once

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "mode.h"
#include "nuage.h"
#include "quaternion.h"

class Ellipsoid
{
public:
    explicit Ellipsoid( Mode const& mode );

    Nuage createCloud( int n, float dmin );
    Distance createDistance( glm::vec3 scale );

private:
    Mode const mode_;
    glm::vec3 scale_{1.f, 1.f, 1.f};
    glm::vec3 center_{0.f, 0.f, 0.f};
    Quaternion orientation_{Quaternion{0.f, 0.f, 0.f, 0.f}};
    Nuage cloud_;
};
