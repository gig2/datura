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
    std::vector<unsigned int> indexes_;
    std::vector<float> colors_;

public:
    Nuage( int n, float dmin, Distance const& distance );
    void generateCloud();

    auto begin() { return std::begin( points_ ); };
    auto end() { return std::end( points_ ); }

    auto const begin() const { return std::cbegin( points_ ); }
    auto const end() const { return std::cend( points_ ); }


    void refreshBuffer();
    // OpenGLMeshRender interface
    using PointT = glm::vec3;

    using PointScalarT = float;


    int getNumIndex() const { return indexes_.size(); }
    int getNumVertices() const { return points_.size(); }
    int getNumColors() const { return colors_.size(); }

    unsigned int const* getIndexesPointer() const { return indexes_.data(); }
    PointT const* getVerticesPointer() const { return points_.data(); }
    float const* getColorsPointer() const { return colors_.data(); }
};
