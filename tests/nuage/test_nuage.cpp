#include "constants.h"
#include "distance.h"
#include "nuage.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"


#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>

using testing::DoubleEq;
using testing::Each;
using testing::FloatEq;
using testing::Ge;
using testing::Le;
using testing::Not;


float dtl2( glm::vec3 const& points )
{
    float const x = points[ dirX ];
    float const y = points[ dirY ];
    float const z = points[ dirZ ];

    float const x2 = x * x;
    float const y2 = y * y;
    float const z2 = z * z;

    return std::sqrt( x2 + y2 + z2 );
}


TEST( aNuageWithEuclideanDist, isContainedInSphere )
{
    //

    auto euclideanDist = Distance{glm::vec3{1.f, 1.f, 1.f}};

    Nuage nuage{5, 0.25, euclideanDist};
    nuage.generateCloud();

    std::vector<float> distance;

    std::transform( std::cbegin( nuage ), std::cend( nuage ), std::back_inserter( distance ),
                    []( auto const& points ) { return dtl2( points ); } );


    // we expect within the sphere

    EXPECT_THAT( distance, Each( Le( 1.f ) ) );

    // we expect not only at the boundary
    EXPECT_THAT( distance, Not( Each( Ge( 1.f ) ) ) );
}
