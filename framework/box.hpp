#ifndef BOX_HPP
#define BOX_HPP


#include "shape.hpp"
#include <iostream>
#include <glm/vec3.hpp>
#include <catch.hpp>
#include "strike.hpp"


class Box : public Shape
{
public:
    Box (glm::vec3 const& min , glm::vec3 const& max , std::string const& name, Material const& material);
    Box();
    ~Box();

    void setMax( glm::vec3 max) ;
    void setMin( glm::vec3 min) ;
  
    glm::vec3 getMax() const;
    glm::vec3 getMin() const;

    float area() const override; //abstrakte M. = rein virtuelle Methode
    float volume() const override;

    std::ostream& print(std::ostream& os ) const override;

    //aufgabe 6.3
    bool intersect( Ray const& ray , float& t ) const override;
    Strike intersection (Ray const& ray, float& t) const override;

private:
    glm::vec3 min_ ;
    glm::vec3 max_ ;
};



#endif // define BOX_HPP 
