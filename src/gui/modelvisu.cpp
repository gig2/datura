#include "modelvisu.h"

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif
#include <glm/gtx/euler_angles.hpp>


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



    // cloud_ = Nuage{50, 0.01, Distance{glm::vec3{1.f, 1.f, 1.f}}};
    ellipsoid.setScale( glm::vec3{1.f, 10.f, 1.f} );
    cloud_ = ellipsoid.computeTransform();
    cloud_.generateCloud();

    look_ = transformation_.lookAt( glm::vec3{-1.f, 1.f, -1.f}, glm::vec3{0.f, 0.f, 0.f},

                                    glm::vec3{0.f, 1.f, 0.f} );

    cloudNode_ = std::make_shared<MeshNode<Nuage>>( cloud_ );
    cloud_.refreshBuffer();

    cloudNode_->updateVertexBuffer();
}

void ModelVisu::resizeGL( int width, int height )
{
    //
    float near = 0.01;
    float far  = 100;
    float fov  = 70.;

    // need to calculate projection here

    projection_
        = transformation_.perspective( fov, static_cast<float>( width ) / height, near, far );
    projection_ = glm::perspective( fov, static_cast<float>( width ) / height, near, far );
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
