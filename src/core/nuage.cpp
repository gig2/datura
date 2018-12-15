#include <random>
#include <algorithm>
#include <iostream>

#include "nuage.h"

Nuage::Nuage(int n, float dmin) : n_(n), dmin_(dmin){

}

void Nuage::generateCloud(){
    const float sphereRadius = 1.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-sphereRadius, sphereRadius);
    while(int(points_.size()) < n_){
        float x, y, z;
        //Generate a random point until it's in the sphere.
        do{
            x = dis(gen);
            y = dis(gen);
            z = dis(gen);
        }while(x*x + y*y + z*z > float(std::pow(sphereRadius, 2)));

        glm::vec3 point(x, y, z);

        //Check if this new point is not too close (< dmin_)
        //of an existing point in points_ table.
        bool should_insert = std::all_of(
            points_.begin(),
            points_.end(),
            [&point, this](auto const & pt){
                float distance;
                distance = std::sqrt(std::pow(point.x - pt.x, 2) + std::pow(point.y - pt.y, 2) + std::pow(point.z - pt.z, 2));
                return distance >= dmin_;
            }
        );
        if(should_insert) points_.push_back(point);
    }
    /*for(int i = 0; i < int(points_.size()); i++){
        std::cout << points_[i].x << " " << points_[i].y << " " << points_[i].z << std::endl;
    }
    std::cout << points_.size() << std::endl;*/
}
