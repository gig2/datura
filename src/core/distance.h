#pragma once

#include <glm/vec3.hpp>

class Distance
{
private:
    glm::vec3 scale_;

public:
    explicit Distance( glm::vec3 const& s );
    float operator()( glm::vec3 const& lhs, glm::vec3 const& rhs );
};
