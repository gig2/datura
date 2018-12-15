#include "transformation.h"

transformation::transformation(std::unique_ptr<transformationimpl> ptr)
{
    impl_ = std::unique_ptr<transformationimpl>(ptr.get());
}

glm::mat4 transformation::scale(glm::vec3 scale){
    return impl_.get()->scale(scale);
}

void transformation::rotate(glm::vec3 axis, float angle){
    impl_.get()->rotate(axis, angle);
}

glm::mat4 transformation::translate(glm::mat4 matrix, glm::vec3 direction){
    return impl_.get()->translate(matrix, direction);
}

void transformation::lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up){
    impl_.get()->lookAt(position, target, up);
}

void transformation::perspective(float fov, float aspect, float near, float far){
    impl_.get()->perspective(fov, aspect, near, far);
}

glm::vec4 transformation::transformVector(glm::mat4 matrix, glm::vec4 vector){
    return impl_.get()->transformVector(matrix, vector);
}
