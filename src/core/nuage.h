#pragma once

#include <vector>
#include <glm/vec3.hpp>

#include "distance.h"

class Nuage
{
private:
    int n_; //Number of points in this cloud.
    float dmin_; //Minimal distance between points in this cloud.
    Distance distance_;
    std::vector<glm::vec3> points_;

public:
    Nuage(){}
    Nuage(int n, float dmin);
    void generateCloud();
};
