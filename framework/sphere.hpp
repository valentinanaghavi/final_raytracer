#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
//#include "Ray.hpp"
#include"strike.hpp"
#include<glm/glm.hpp>
#include<glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <iostream>
#include <string>

//struct Strike;

class Sphere : public Shape
{

public:
    Sphere();
    Sphere(glm::vec3 const& center, float const& radius , std::string const& name, Material const& material);
    ~Sphere();

    void setCenter(glm::vec3 center) ;
    void setRadius(float radius) ;

    glm::vec3 const& getCenter() const;
    float const& getRadius() const;

    //float area() const override; //abstrakte M. = rein virtuelle Methode
    //float volume() const override;
    
    std::ostream& print(std::ostream& os ) const override;

    bool intersect (Ray const& ray, float& distance) const override;
    Strike intersection (Ray const& ray) const override;

private:
    glm::vec3 center_ ;
    float radius_ ;

};




#endif // define SPHERE_HPP 
