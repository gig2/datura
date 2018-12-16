#include "distance.h"

#include "constants.h"

#include <cmath>

Distance::Distance( glm::vec3 const& s )
    : scale_{s}
{
}

float Distance::operator()( glm::vec3 const& lhs, glm::vec3 const& rhs )
{
    float const dx = rhs[ dirX ] - lhs[ dirX ];

    float const dy = rhs[ dirY ] - lhs[ dirY ];

    float const dz = rhs[ dirZ ] - lhs[ dirZ ];

    float const dx2 = dx * dx;
    float const dy2 = dy * dy;
    float const dz2 = dz * dz;

    float const sx2 = scale_[ dirX ] * scale_[ dirX ];
    float const sy2 = scale_[ dirY ] * scale_[ dirY ];
    float const sz2 = scale_[ dirZ ] * scale_[ dirZ ];

    return std::sqrt( sx2 * dx2 + sy2 * dy2 + sz2 * dz2 );
}
