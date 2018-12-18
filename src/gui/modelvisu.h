#pragma once

#include <GL/glew.h>

#include "OpenGLMeshRender/meshnode.h"
#include "OpenGLShader/shader.h"

#include <QOpenGLWidget>

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <memory>
#include <vector>

#include "ellipsoid.h"
#include "pca.h"
#include "transformation.h"


class ModelVisu : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit ModelVisu( QWidget *parent );

public slots:
    void setCenterX( double x );
    void setCenterY( double y );
    void setCenterZ( double z );

    void setScaleX( double a );
    void setScaleY( double b );
    void setScaleZ( double c );

    void setRotateAxisX( double x );
    void setRotateAxisY( double y );
    void setRotateAxisZ( double z );

    void setRotateAngle( double theta );

    void setNpoints( int nPoint );

    void setDmin( double dmin );

    void computeCloud();


protected:
    void initializeGL() override;

    void resizeGL( int width, int height ) override;

    void paintGL() override;


private:
    void computeCloudAndPca_();


    glm::vec3 center_{0.f, 0.f, 0.f};
    glm::vec3 scale_{1.f, 1.f, 1.f};

    glm::vec3 rotateAxis_{1.f, 0.f, 0.f};

    float rotateAngle_{0.f};

    int nPoints_{500};
    float dmin_{0.0005};


    // get them from shader
    int const positionLocation_{0};
    int const colorLocation_{1};


    Ellipsoid ellipsoid{Mode::manual};

    Nuage cloud_{1, 0.01f, Distance{glm::vec3{1.f, 1.f, 1.f}}};

    std::shared_ptr<MeshNode<Nuage>> cloudNode_;

    Transformation transformation_{Mode::manual};

    Pca pca{Mode::automatic};

    std::vector<glm::vec3> centeredPoints_;

    glm::mat3 inertia_;

    glm::mat4 projection_;
    glm::mat4 look_;


    S3DE::Shader simpleShader_;
};
