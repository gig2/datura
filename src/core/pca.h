#pragma once

#include "mode.h"

#include <memory>
#include <vector>
// eigen stuf
#include <Eigen/Dense>

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/vec3.hpp>




#include "barycenter.h"
#include "pcaimpl.h"
#include "recenter.h"

class Pca
{
private:
    std::unique_ptr<PcaImpl> const pimpl_;
    std::vector<glm::vec3> points_;
    Eigen::Matrix3f inertia_;
    Eigen::Matrix3cf eigenVectors_;
    Eigen::Vector3cf eigenValues_;

    template <typename InputIt1, typename InputIt2>
    Eigen::Matrix3f computeInertia_( InputIt1 begin, InputIt2 end )
    {
        points_.clear();
        points_.resize( std::distance( begin, end ) );

        auto barycentre = barycenter( begin, end, glm::vec3{0.f, 0.f, 0.f} );

        recenter( barycentre, begin, end, std::back_inserter( points_ ) );

        float sx2{0.f};
        float sy2{0.f};
        float sz2{0.f};

        float sxy{0.f};
        float sxz{0.f};
        float syz{0.f};

        for ( auto const& point : points_ )
        {
            sx2 += point.x * point.x;
            sy2 += point.y * point.y;
            sz2 += point.z * point.z;


            sxy += point.x * point.y;
            sxz += point.x * point.z;
            syz += point.y * point.z;
        }

        Eigen::Matrix3f inertia;

        inertia( 0, 0 ) = sx2;
        inertia( 0, 1 ) = sxy;
        inertia( 0, 2 ) = sxz;

        inertia( 1, 0 ) = sxy;
        inertia( 1, 1 ) = sy2;
        inertia( 1, 2 ) = syz;

        inertia( 2, 0 ) = sxz;
        inertia( 2, 1 ) = syz;
        inertia( 2, 2 ) = sz2;

        return inertia;
    }

public:
    explicit Pca( Mode const& mode );

    template <typename InputIt1, typename InputIt2>
    void computePca( InputIt1 begin, InputIt2 end )
    {
        inertia_ = computeInertia_( begin, end );
        pimpl_->setupInertia( inertia_ );
        eigenVectors_ = pimpl_->eigenVectors();
        eigenValues_  = pimpl_->eigenValues();
    }

    Eigen::Matrix3cf const& eigenVectors() const { return eigenVectors_; }
    Eigen::Vector3cf const& eigenValues() const { return eigenValues_; }
};
