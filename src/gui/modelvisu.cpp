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


    cloud_ = ellipsoid.computeTransform();
}

void ModelVisu::resizeGL( int width, int height )
{
    //
    float near = 0.01;
    float far  = 100;
    float fov  = 70.;

    // need to calculate projection here
}

void ModelVisu::paintGL()
{
    //
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glEnable( GL_DEPTH_TEST );

    simpleShader_.Enable();

    simpleShader_.Disable();
}
