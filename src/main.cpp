#include "gui/mainwindow.h"

#include <QApplication>
#include <iostream>

#include "manualtrans.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    MainWindow w;
    w.show();

    /*manualtrans mt = manualtrans();
    //glm::mat4 mtest = mt.translate(glm::mat4(), glm::vec3(10,0,0));
    glm::mat4 mtest = mt.scale(glm::vec3(2.0f, 2.0f, 2.0f));
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
