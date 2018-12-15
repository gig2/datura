#ifndef MANUALTRANS_H
#define MANUALTRANS_H

#include "transformationimpl.h"
#include "mode.h"

class manualtrans : public transformationimpl
{
public:
    manualtrans();
    void scale(glm::vec3 scale);
    void rotate(glm::vec3 axis, float angle);
    void translate(glm::vec3 direction);
    void lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up);
    void perspective(float fov, float aspect, float near, float far);
};

#endif // MANUALTRANS_H
