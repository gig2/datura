#pragma once

#include <Eigen/Dense>

class PcaImpl
{
public:
    virtual void setupInertia( Eigen::Matrix3f const& inertia ) = 0;
    virtual Eigen::Matrix3cf const& eigenVectors() const        = 0;
    virtual Eigen::Vector3cf const& eigenValues() const         = 0;

    virtual ~PcaImpl() = default;
};
