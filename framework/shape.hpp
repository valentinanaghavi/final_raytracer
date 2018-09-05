#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp" 
#include "Ray.hpp"
#include "material.hpp"
#include "strike.hpp"
#include <glm/glm.hpp>

#include <iostream>
#include <string>
#include <memory> //manage dynamic shared_ptr


struct Strike;

class Shape //abstrakte Basisklasse
{

public:
    Shape();
    Shape(std::string const& name , Material const& material);
    //virtual ~Shape();
    ~Shape();

    virtual float area() const = 0; //pure virtual -> muss in der abgl. Klasse ueberschrieben werden, um Objekt instanziieren zu koennen , Klasse kann nicht instanziiert werden
    virtual float volume() const = 0; // Methodeninterface wird vererbt, keine Implementierung 

    void setName(std::string name) ;
    void setMaterial(Material material) ;
    void setWorld_trans(glm::mat4 world_transformation);
    void setWorld_trans_inv(glm::mat4 world_transformation_inv);

    std::string getName() const;
    Material getMaterial() const;
    glm::mat4 getWorld_trans() const;
    glm::mat4 getWorld_trans_inv() const;
    
    virtual std::ostream& print(std::ostream& os ) const ;

    //aufgabe 6.3
    virtual bool intersect ( Ray const& ray , float& t ) const = 0;
    virtual Strike intersection (Ray const& ray, float& t) const = 0;


private:
    std::string name_ ;
    Material material_ ;

    glm::mat4 world_transformation_ ;
    glm::mat4 world_tranformation_inv_;


};

    std::ostream& operator<<(std::ostream& os , Shape const& s) ;
    std::ostream& operator<<(std::ostream& os , std::shared_ptr<Shape> const& s) ;

#endif // define SHAPE_HPP 

