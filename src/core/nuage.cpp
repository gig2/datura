#include <algorithm>
#include <iostream>
#include <numeric>
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

glm::vec3 Nuage::cloudBarycenter()
{
    glm::vec3 barycenter_to_return{0.f, 0.f, 0.f};
    int nbpoints = points_.size();

    for ( int i = 0; i < nbpoints; i++ )
    {
        barycenter_to_return[ dirX ] += points_[ i ][ dirX ];
        barycenter_to_return[ dirY ] += points_[ i ][ dirY ];
        barycenter_to_return[ dirZ ] += points_[ i ][ dirZ ];
    }
    barycenter_to_return[ dirX ] /= nbpoints;
    barycenter_to_return[ dirY ] /= nbpoints;
    barycenter_to_return[ dirZ ] /= nbpoints;

    // std::cout << barycenter_to_return.x << " " << barycenter_to_return.y << " " <<
    // barycenter_to_return.z << std::endl;
    return barycenter_to_return;
}

glm::mat3 Nuage::inertiaMatrix()
{
    glm::mat3 matrix_to_return{0.f};
    glm::vec3 b                            = cloudBarycenter();
    std::vector<glm::vec3> centered_points = points_;

    // Recenter all points of cloud by its barycenter.
    for ( int i = 0; i < centered_points.size(); i++ )
    {
        centered_points[ i ] -= b;
        matrix_to_return[ 0 ][ 0 ] += centered_points[ i ][ dirX ] * centered_points[ i ][ dirX ];
        matrix_to_return[ 0 ][ 1 ] += centered_points[ i ][ dirX ] * centered_points[ i ][ dirY ];
        matrix_to_return[ 0 ][ 2 ] += centered_points[ i ][ dirX ] * centered_points[ i ][ dirZ ];
        matrix_to_return[ 1 ][ 0 ] += centered_points[ i ][ dirY ] * centered_points[ i ][ dirX ];
        matrix_to_return[ 1 ][ 1 ] += centered_points[ i ][ dirY ] * centered_points[ i ][ dirY ];
        matrix_to_return[ 1 ][ 2 ] += centered_points[ i ][ dirY ] * centered_points[ i ][ dirZ ];
        matrix_to_return[ 2 ][ 0 ] += centered_points[ i ][ dirZ ] * centered_points[ i ][ dirX ];
        matrix_to_return[ 2 ][ 1 ] += centered_points[ i ][ dirZ ] * centered_points[ i ][ dirY ];
        matrix_to_return[ 2 ][ 2 ] += centered_points[ i ][ dirZ ] * centered_points[ i ][ dirZ ];
    }

    return matrix_to_return;
}
void Nuage::refreshBuffer()
{
    //
    int const numberColors = 3;
    int const numIndexes   = points_.size();

    indexes_.clear();
    indexes_.reserve( numIndexes );

    indexes_.push_back( 0 );
    indexes_.push_back( 1 );
    indexes_.push_back( 2 );

    for ( unsigned int i = 0; i < numIndexes; ++i )
    {
        indexes_.push_back( i );
    }

    colors_.clear();
    colors_.reserve( numIndexes * numberColors );
    for ( unsigned int i = 0; i < numIndexes * numberColors; i += 3 )
    {
        colors_.push_back( 1.f );
        colors_.push_back( 1.f );
        colors_.push_back( 1.f );
    }
}
