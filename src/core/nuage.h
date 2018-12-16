#pragma once

#include <glm/vec3.hpp>
#include <iterator>
#include <vector>

#include "distance.h"

class Nuage
{
private:
    int n_;      // Number of points in this cloud.
    float dmin_; // Minimal distance between points in this cloud.
    Distance distance_;
    std::vector<glm::vec3> points_;

public:
    Nuage( int n, float dmin, Distance const& distance );
    void generateCloud();

    auto begin() { return std::begin( points_ ); };
    auto end() { return std::end( points_ ); }

    auto const begin() const { return std::cbegin( points_ ); }
    auto const end() const { return std::cend( points_ ); }
};
