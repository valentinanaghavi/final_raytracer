#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Ray.hpp"
#include <glm/vec3.hpp>
#include <string>
#include <iostream>

struct Camera 
{
    

    std::string name_;
    float fovX_;  //Oeffnungswinkel der Kamera
    glm::vec3 eye_; // von position zu eye geandert
    glm::vec3 direction_;
    glm::vec3 up_;


    Camera(std::string const& name, float fovX, glm::vec3 const& eye, glm::vec3 const& direction, glm::vec3 const& up):
    name_(name),
    fovX_(fovX),
    eye_(eye),
    direction_(direction),
    up_(up)
    {};

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
    
    Ray camera_ray(float x, float y, float width , float height )
    {
        float distance_ = 0.5 / tan( fovX_ * M_PI /360); // Oeffnungswinkel -> Bogenmaß
        
        glm::vec3 direction {float(x)*(1 / float(width)) - 0.5 , 
                             float(y) *(1/ float(height))- 0.5 , 
                             -1 * distance_};

        Ray tmpRay{{0.0f,0.0f,0.0f} , direction};

        glm::mat4 camera_matrix(camera_transformation());
        
        Ray newRay (transformRay(camera_matrix , tmpRay));
        return newRay;
    }

    glm::mat4 camera_transformation()
    {   

        glm::vec3 normalized_dir = glm::normalize(direction_);
        glm::vec3 n = glm::normalize(direction_);
       // glm::vec3 u_ = glm::normalize(glm::cross(normalized_dir, up_)); //u steht senkrecht auf direction(n) und up
       // glm::vec3 v_ = glm::normalize(glm::cross(u_ , normalized_dir));  //stellt sicher , dass up senkrecht auf u und n ist
        glm::vec3 e = eye_;
        glm::vec3 up = up_;
        glm::vec3 u = glm::normalize(glm::cross(n,up));
        glm::vec3 v = glm::normalize(glm::cross(u,n));


        glm::mat4 tc;
        tc[3] = glm::vec4(e,1.0);
        tc[2] = glm::vec4(n* -1.0f,0.0) ;
        tc[1] = glm::vec4(v,0.0);
        tc[0] = glm::vec4(u,0.0);
      /* glm::mat4 c{ u_.x , v_.x , -normalized_dir.x , eye_.x,
                    u_.y , v_.y , -normalized_dir.y , eye_.y,
                    u_.z , v_.z , -normalized_dir.z , eye_.z, 
                       0 ,    0 ,             0 ,          1
       };

       return c ;*/
       return tc;
    }
    

  friend std::ostream& operator<<(std::ostream& os, Camera const& c)
  {
    os << "Name: " << c.name_ << "\n" << "fovX: " << c.fovX_ << "\n"
    << "eye: (" << c.eye_.x << "," << c.eye_.y << "," << c.eye_.z <<") \n"
    << "direction: (" << c.direction_.x << "," << c.direction_.y << "," << c.direction_.z <<") \n"
	<< "up: (" << c.up_.x << "," << c.up_.y << "," << c.up_.z <<")"
    << " \n";
    return os;
  }

};







#endif