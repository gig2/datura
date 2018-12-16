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

class ModelVisu : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit ModelVisu( QWidget *parent );

protected:
    void initializeGL() override;

    void resizeGL( int width, int height ) override;

    void paintGL() override;


private:
    // get them from shader
    int const positionLocation_{0};
    int const colorLocation_{1};


    Ellipsoid ellipsoid{Mode::manual};

    Nuage cloud_{1, 0.01f, Distance{glm::vec3{1.f, 1.f, 1.f}}};

    std::shared_ptr<MeshNode<Nuage>> nuageNode_;



    S3DE::Shader simpleShader_;
};
