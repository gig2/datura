#include "ellipsoid.h"

Ellipsoid::Ellipsoid( Mode const& mode )
    : mode_{mode}
    , orientation_{Quaternion( 0, 0, 0, 0 )}
    , cloud_{createCloud( 50, 0.25 )}

{
}

Nuage Ellipsoid::createCloud( int n, float dmin )
{
    Nuage cloud_to_return = Nuage( n, dmin, Distance{scale_} );
    cloud_to_return.generateCloud();
    return cloud_to_return;
}

Distance Ellipsoid::createDistance( glm::vec3 scale )
{
    return Distance( scale );
}
