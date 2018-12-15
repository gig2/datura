#include "transformation.h"

transformation::transformation(std::unique_ptr<transformationimpl> ptr)
{
    impl_ = std::unique_ptr<transformationimpl>(ptr.get());
}

void transformation::scale(glm::vec3 scale){
    impl_.get()->scale(scale);
}

void transformation::rotate(glm::vec3 axis, float angle){
    impl_.get()->rotate(axis, angle);
}

void transformation::translate(glm::vec3 direction){
    impl_.get()->translate(direction);
}

void transformation::lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up){
    impl_.get()->lookAt(position, target, up);
}

void transformation::perspective(float fov, float aspect, float near, float far){
    impl_.get()->perspective(fov, aspect, near, far);
}
