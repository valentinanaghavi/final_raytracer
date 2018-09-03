#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Ray.hpp"
#include <glm/vec3.hpp>
#include <string>

struct Camera 
{
    
    Camera(std::string const& name, float fovX, glm::vec3 const& eye, glm::vec3 const& direction, glm::vec3 const& up):
    name_(name),
    fovX_(fovX),
    eye_(eye),
    direction_(direction),
    up_(up)
    {};

//Dieser Konstruktor vermutlich nicht mehr noetig , durch 7.3 erweiterung s.o.
    Camera(std::string const& name, float fovX):
    name_(name),
    fovX_(fovX),
    eye_(0.0f, 0.0f, 0.0f),
    direction_(0.0f, 0.0f, -1.0f),
    up_(0.0f, 0.0f, 0.0f)
    {};

    Camera():
    name_("noName"),
    fovX_(45),
    eye_(0.0f, 0.0f, 0.0f),
    direction_(0.0f, 0.0f, -1.0f),
    up_(0.0f, 1.0f, 0.0f)
    {};
    
    glm::vec3 camera_ray()
    {
        
    }
    glm::mat4 camera_transformation()
    {
       glm::vec3 normalized_dir = glm::normalize(direction_);
       glm::vec3 u_ = glm::normalize(glm::cross(normalized_dir, up_)); //u steht senkrecht auf direction(n) und up
       glm::vec3 v_ = glm::normalize(glm::cross(u_ , normalized_dir));  //stellt sicher , dass up senkrecht auf u und n ist
       
       glm::mat4 c{ u_.x , v_.x , -normalized_dir.x , eye_.x,
                    u_.y , v_.y , -normalized_dir.y , eye_.y,
                    u_.z , v_.z , -normalized_dir.z , eye_.z, 
                       0 ,    0 ,             0 ,          1
       };

       return c ;
    }
    
    std::string name_;
    float fovX_;  //Oeffnungswinkel der Kamera
    glm::vec3 eye_; // von position zu eye geandert
    glm::vec3 direction_;
    glm::vec3 up_;







};




#endif