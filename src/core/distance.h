#pragma once

#include <glm/vec3.hpp>

class Distance
{
private:
    glm::vec3 scale_;

public:
    Distance(){}
    Distance(glm::vec3 s);
    void operate();
};
