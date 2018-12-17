#include "gui/mainwindow.h"

#include <QApplication>
#include <iostream>

#include "manualtrans.h"
#include "ellipsoid.h"
#include "mode.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    MainWindow w;
    w.show();

    Ellipsoid e = Ellipsoid(Mode::manual);
    Nuage n = e.createCloud(50, 0.20);
    glm::vec3 vtest = n.cloudBarycenter();

    /*Manualtrans mt = Manualtrans();
    //glm::mat4 mtest = mt.translate(glm::mat4(), glm::vec3(10,0,0));
    //glm::mat4 mtest = mt.scale(glm::vec3(2.0f, 2.0f, 2.0f));
    //glm::mat4 mtest = mt.lookAt(glm::vec3(0,0,-15), glm::vec3(0,0,0), glm::vec3(0,1,0));
    glm::mat4 mtest = mt.perspective(35.f, 1.f, 0.1f, 100.f);
    glm::vec4 vtest = mt.transformVector(mtest, glm::vec4(2.1f, 1.5f, 0.7f, 0));

    for(int i = 0 ; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            std::cout << mtest[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < 4; i++){
        std::cout << vtest[i] << std::endl;
    }*/

    return a.exec();
}
