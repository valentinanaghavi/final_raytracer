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
#include <vector>

//struct Strike;

class Shape //abstrakte Basisklasse
{

public:
    Shape();
    Shape(std::string const& name , Material const& material);
    //virtual ~Shape();
    ~Shape();

    /*virtual float area() const = 0; //pure virtual -> muss in der abgl. Klasse ueberschrieben werden, um Objekt instanziieren zu koennen , Klasse kann nicht instanziiert werden
    virtual float volume() const = 0; // Methodeninterface wird vererbt, keine Implementierung */

    virtual void setName(std::string name) ;
    virtual void setMaterial(Material material) ;
    virtual void setWorld_trans(glm::mat4 world_transformation);
    virtual void setWorld_trans_inv(glm::mat4 world_transformation_inv);

    virtual std::string getName() const;
    virtual Material getMaterial() const;
    virtual glm::mat4 getWorld_trans() const;
    virtual glm::mat4 getWorld_trans_inv() const;
    
    virtual std::ostream& print(std::ostream& os ) const ;

    //aufgabe 6.3
    virtual bool intersect ( Ray const& ray , float& t ) const = 0;
    virtual Strike intersection (Ray const& ray) const = 0;

    //Composite
    virtual void remove(std::shared_ptr<Shape>& shape) {}
    virtual void add(std::shared_ptr<Shape>& shape) {}
    virtual std::vector<std::shared_ptr<Shape>> getComposite() {}




private:
    std::string name_ ;
    Material material_ ;

    glm::mat4 world_transformation_ ;
    glm::mat4 world_transformation_inv_;


};

    std::ostream& operator<<(std::ostream& os , Shape const& s) ;
    std::ostream& operator<<(std::ostream& os , std::shared_ptr<Shape> const& s) ;

#endif // define SHAPE_HPP 

