#include "pcaauto.h"

#include <Eigen/Eigenvalues>

void PcaAuto::setupInertia( Eigen::Matrix3f const& inertia )
{
    inertia_ = inertia;

    auto solver = Eigen::EigenSolver<Eigen::Matrix3f>{inertia_, true};

    eigenVectors_ = solver.eigenvectors();
    eigenValues_  = solver.eigenvalues();
}
