#include "modelvisu.h"

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif
#include <glm/gtx/euler_angles.hpp>

#include "constants.h"
#include "recenter.h"

#include <iostream>


// eigen stuf
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

ModelVisu::ModelVisu( QWidget *parent )
    : QOpenGLWidget( parent )
{
    int major = 3;
    int minor = 2;

    QSurfaceFormat format;

    format.setDepthBufferSize( 24 );
    format.setStencilBufferSize( 8 );
    format.setVersion( major, minor );
    format.setProfile( QSurfaceFormat::CoreProfile );

    setFormat( format );

    create();
}



void ModelVisu::initializeGL()
{
    glewExperimental = GL_TRUE;
    GLenum initGlew{glewInit()};

    if ( initGlew != GLEW_OK )
    {
        throw std::runtime_error(
            reinterpret_cast<const char *>( glewGetErrorString( initGlew ) ) );
    }




    simpleShader_.setVertexShader( "shader/color.vert" );
    simpleShader_.setFragmentShader( "shader/color.frag" );
    try
    {
        simpleShader_.Load();
    }
    catch ( std::exception const &e )
    {
        std::cerr << e.what() << "\n";
    }
    catch ( std::string const &errorStr )
    {
        std::cerr << errorStr << "\n";
    }
    catch ( ... )
    {
        std::cerr << "unknown exception\n";
    }

    glClearColor( .0f, 0.f, 0.f, .0f );

    ellipsoid.setScale( glm::vec3{2.f, 1.f, 3.f} );
    ellipsoid.setCenter( glm::vec3{-5.f, 0.f, 0.f} );
    ellipsoid.setOrientation( transformation_.rotate( glm::vec3{0.f, 1.f, 0.f}, M_PI / 6.f ) );
    cloud_ = ellipsoid.computeTransform();
    cloud_.generateCloud();

    // ok manual look At not working
    look_ = transformation_.lookAt( glm::vec3{0.f, -10.f, 0.f}, glm::vec3{0.f, 0.f, 0.f},
                                    glm::vec3{0.f, 0.f, 1.f} );

    look_ = glm::lookAt( glm::vec3{0.f, -10.f, 0.f}, glm::vec3{0.f, 0.f, 0.f},
                         glm::vec3{0.f, 0.f, 1.f} );

    cloudNode_ = std::make_shared<MeshNode<Nuage>>( cloud_ );
    cloud_.refreshBuffer();


    cloudNode_->updateVertexBuffer();


    glm::vec3 barycentre
        = std::accumulate( std::cbegin( cloud_ ), std::cend( cloud_ ), glm::vec3{0.f, 0.f, 0.f} );

    barycentre /= std::distance( std::cbegin( cloud_ ), std::cend( cloud_ ) );


    centeredPoints_.clear();
    centeredPoints_.resize( std::distance( std::cbegin( cloud_ ), std::cend( cloud_ ) ) );

    // glm::vec3 barycentre{-5.f, 0.f, 0.f};

    recenter( barycentre, std::cbegin( cloud_ ), std::cend( cloud_ ),
              std::back_inserter( centeredPoints_ ) );


    float sx2{0.f};
    float sy2{0.f};
    float sz2{0.f};

    float sxy{0.f};
    float sxz{0.f};
    float syz{0.f};

    for ( auto const &point : centeredPoints_ )
    {
        sx2 += point.x * point.x;
        sy2 += point.y * point.y;
        sz2 += point.z * point.z;


        sxy += point.x * point.y;
        sxz += point.x * point.z;
        syz += point.y * point.z;
    }

    inertia_[ dirX ].x = sx2;
    inertia_[ dirX ].y = sxy;
    inertia_[ dirX ].z = syz;

    inertia_[ dirY ].x = sxy;
    inertia_[ dirY ].y = sy2;
    inertia_[ dirY ].z = syz;

    inertia_[ dirZ ].x = sxz;
    inertia_[ dirZ ].y = syz;
    inertia_[ dirZ ].z = sz2;

    Eigen::Matrix3f inertia;


    for ( int i = 0; i < 3; ++i )
    {
        for ( int j = 0; j < 3; ++j )
        {
            inertia( i, j ) = inertia_[ j ][ i ];
            std::cout << inertia_[ j ][ i ] << " ";
        }
        std::cout << "\n";
    }

    auto solver = Eigen::EigenSolver<Eigen::Matrix3f>{inertia, true};

    auto eigenVector = solver.eigenvectors();

    std::cout << eigenVector << "\n";

    auto eigenValues = solver.eigenvalues();

    std::cout << eigenValues << "\n";
}

void ModelVisu::resizeGL( int width, int height )
{
    //
    float near = 0.01;
    float far  = 100;
    float fov  = 70.;

    projection_
        = transformation_.perspective( fov, static_cast<float>( width ) / height, near, far );
}

void ModelVisu::paintGL()
{
    //
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glEnable( GL_DEPTH_TEST );

    simpleShader_.Enable();

    glm::mat4 mvp = projection_ * look_;


    auto mvpLoc = simpleShader_.GetUniformLocation( "MVP" );

    glUniformMatrix4fv( mvpLoc, 1, GL_FALSE, glm::value_ptr( mvp ) );

    cloudNode_->drawPoints();

    simpleShader_.Disable();
}
