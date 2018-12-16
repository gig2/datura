#include <algorithm>
#include <iostream>
#include <random>

#include "constants.h"
#include "nuage.h"

Nuage::Nuage( int n, float dmin, Distance const& distance )
    : n_( n )
    , dmin_( dmin )
    , distance_{distance}
{
}

void Nuage::generateCloud()
{
    const float sphereRadius = 1.0f;

    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_real_distribution<float> dis( -sphereRadius, sphereRadius );

    auto isIn = [&sphereRadius]( auto const& points ) {
        auto const x2 = points[ dirX ] * points[ dirX ];
        auto const y2 = points[ dirY ] * points[ dirY ];
        auto const z2 = points[ dirZ ] * points[ dirZ ];

        return std::sqrt( x2 + y2 + z2 ) <= sphereRadius;
    };

    while ( points_.size() < static_cast<std::size_t>( n_ ) )
    {
        glm::vec3 point{0.f, 0.f, 0.f};
        // Generate a random point until it's in the sphere.
        do
        {
            point[ dirX ] = dis( gen );
            point[ dirY ] = dis( gen );
            point[ dirZ ] = dis( gen );

        } while ( !isIn( point ) );

        // Check if this new point is not too close (< dmin_)
        // of an existing point in points_ table.
        bool should_insert
            = std::all_of( points_.begin(), points_.end(), [&point, this]( auto const& pt ) {
                  return distance_( point, pt ) >= dmin_;
              } );
        if ( should_insert )
            points_.push_back( point );
    }


    /*for(int i = 0; i < int(points_.size()); i++){
        std::cout << points_[i].x << " " << points_[i].y << " " << points_[i].z << std::endl;
    }
    std::cout << points_.size() << std::endl;*/
}
