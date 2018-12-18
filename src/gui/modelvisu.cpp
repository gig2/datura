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

#include "barycenter.h"

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

    computeCloudAndPca_();

#if 0
    ellipsoid.setScale( glm::vec3{2.f, 1.f, 3.f} );
    ellipsoid.setCenter( glm::vec3{-5.f, 0.f, 0.f} );
    ellipsoid.setOrientation( transformation_.rotate( glm::vec3{0.f, 1.f, 0.f}, M_PI / 6.f ) );
    cloud_ = ellipsoid.computeTransform();
    cloud_.generateCloud();

#endif
    look_ = transformation_.lookAt( glm::vec3{0.f, -10.f, 0.f}, glm::vec3{0.f, 0.f, 0.f},
                                    glm::vec3{0.f, 0.f, 1.f} );

#if 0

    cloudNode_ = std::make_shared<MeshNode<Nuage>>( cloud_ );
    cloud_.refreshBuffer();


    cloudNode_->updateVertexBuffer();

    pca.computePca( std::cbegin( cloud_ ), std::cend( cloud_ ) );

    std::cout << "Eigen values are: \n";
    auto const &eigenValues = pca.eigenValues();
    std::cout << eigenValues << "\n";


    std::cout << "Eigen vectors are: \n";
    auto const &eigenVector = pca.eigenVectors();
    std::cout << eigenVector << "\n";
#endif
}




void ModelVisu::setCenterX( double x )
{
    center_[ dirX ] = static_cast<float>( x );
}
void ModelVisu::setCenterY( double y )
{
    center_[ dirY ] = static_cast<float>( y );
}
void ModelVisu::setCenterZ( double z )
{
    center_[ dirZ ] = static_cast<float>( z );
}

void ModelVisu::setScaleX( double a )
{
    scale_[ dirX ] = 2.f * a;
}
void ModelVisu::setScaleY( double b )
{
    scale_[ dirY ] = 2.f * b;
}
void ModelVisu::setScaleZ( double c )
{
    scale_[ dirZ ] = 2.f * c;
}

void ModelVisu::setRotateAxisX( double x )
{
    rotateAxis_[ dirX ] = static_cast<float>( x );
}
void ModelVisu::setRotateAxisY( double y )
{
    rotateAxis_[ dirY ] = static_cast<float>( y );
}
void ModelVisu::setRotateAxisZ( double z )
{
    rotateAxis_[ dirZ ] = static_cast<float>( z );
}

void ModelVisu::setRotateAngle( double theta )
{
    rotateAngle_ = static_cast<float>( theta );
}

void ModelVisu::setNpoints( int nPoint )
{
    nPoints_ = nPoint;
}

void ModelVisu::setDmin( double dmin )
{
    dmin_ = static_cast<float>( dmin );
}

void ModelVisu::computeCloud()
{
    makeCurrent();
    computeCloudAndPca_();
    doneCurrent();
    update();
}


void ModelVisu::computeCloudAndPca_()
{
    ellipsoid.setScale( scale_ );
    ellipsoid.setCenter( center_ );
    ellipsoid.setOrientation(
        transformation_.rotate( glm::normalize( rotateAxis_ ), rotateAngle_ ) );

    ellipsoid.computeCloud( nPoints_, dmin_ );

    cloud_ = ellipsoid.computeTransform();
    cloud_.generateCloud();


    cloudNode_ = std::make_shared<MeshNode<Nuage>>( cloud_ );
    cloud_.refreshBuffer();


    cloudNode_->updateVertexBuffer();

    pca.computePca( std::cbegin( cloud_ ), std::cend( cloud_ ) );

    std::cout << "Eigen values are: \n";
    auto const &eigenValues = pca.eigenValues();
    std::cout << eigenValues << "\n";


    std::cout << "Eigen vectors are: \n";
    auto const &eigenVector = pca.eigenVectors();
    std::cout << eigenVector << "\n";
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
