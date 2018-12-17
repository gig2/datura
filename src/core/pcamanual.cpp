#include "pcamanual.h"

void PcaManual::setupInertia( Eigen::Matrix3f const& inertia )
{
    inertia_ = inertia;
}
