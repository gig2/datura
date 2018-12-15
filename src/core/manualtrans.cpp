#include "manualtrans.h"
#include "quaternion.h"

manualtrans::manualtrans()
{
}

// Build Scale Matrix.
glm::mat4 manualtrans::scale(glm::vec3 scale){
    glm::mat4 matrix_to_return = glm::mat4();
    for(int i = 0; i < 3; i++){
        matrix_to_return[i][i] = scale[i];
    }
    matrix_to_return[3][3] = 1;
    return matrix_to_return;
}

void manualtrans::rotate(glm::vec3 axis, float angle){
    Quaternion q = Quaternion(axis, angle);
}

// Build Translate Matrix.
glm::mat4 manualtrans::translate(glm::mat4 matrix, glm::vec3 direction){
    glm::mat4 matrix_to_return = matrix;
    for(int i = 0; i < 4; i++){
        matrix_to_return[i][i] = 1;
    }
    for(int i = 0; i < 3; i++){
        matrix_to_return[3][i] = direction[i];
    }
    return matrix_to_return;
}

void manualtrans::lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up){

}

void manualtrans::perspective(float fov, float aspect, float near, float far){

}

// Return modified parameter vector thanks to a multiplication
// between given two parameters.
glm::vec4 manualtrans::transformVector(glm::mat4 matrix, glm::vec4 vector){
    glm::vec4 vector_to_return;
    for(int i = 0; i < 4; i++){
        float res = 0.f;
        for(int j = 0; j < 4; j++){
            res += vector[j] * matrix[j][i];
        }
        vector_to_return[i] = res;
    }
    return vector_to_return;
}
