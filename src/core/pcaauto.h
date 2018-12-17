#pragma once
#include "pcaimpl.h"

class PcaAuto : public PcaImpl
{
private:
    Eigen::Matrix3f inertia_;
    Eigen::Matrix3cf eigenVectors_;
    Eigen::Vector3cf eigenValues_;

public:
    void setupInertia( Eigen::Matrix3f const& inertia ) override;

    Eigen::Matrix3cf const& eigenVectors() const override { return eigenVectors_; }

    Eigen::Vector3cf const& eigenValues() const override { return eigenValues_; }
};
