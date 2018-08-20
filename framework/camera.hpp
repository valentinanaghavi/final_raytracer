#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Ray.hpp"
#include <glm/vec3.hpp>

class Camera 
{
    public:
    Camera(std::String const& name, float fovX, glm::vec3 const& position, glm::vec3 const& direction):
    name_(name),
    fovX_(fovX),
    position_(0.0f, 0.0f, 0.0f),
    direction_(0.0f, 0.0f, -1.0f)
    {}

    private:
    std::string name_;
    float fovX_;  //Öffnungswinkel der Kamera
    glm::vec3 position_;
    glm::vec3 direction_;






};




#endif