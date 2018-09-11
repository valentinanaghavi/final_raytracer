#include "material.hpp"

#include <iostream>

Material::Material() :
    name_ {"no Name"},
    ka_ {0.0f, 0.0f, 0.0f}, 
    kd_ {0.0f, 0.0f, 0.0f},
    ks_ {0.0f, 0.0f, 0.0f},
    m_ {0.0f},
    refract_{0.0f},
    opacity_{0.0f}
    {};

Material::Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m) :
    name_ {name},
    ka_ {ka},
    kd_ {kd},
    ks_ {ks},
    m_ {m},
    refract_{0.0f},
    opacity_{0.0f}
    {};

Material::Material(std::string name, Color const& ka, Color const& kd, Color const& ks, float m, float r, float o) :
    name_ {name},
    ka_ {ka},
    kd_ {kd},
    ks_ {ks},
    m_ {m},
    refract_{r},
    opacity_{o}
{};

std::ostream& Material :: print(std::ostream& os ) const 
{
    os << "\n Name: " << name_ << "\n"
	<< "ambient reflection: " << ka_
	<< "diffuse reflection: " << kd_
	<< "specular reflection: " << ks_
    << "specular reflection exponent: " << m_ 
    << "brechungsindex" << refract_
    << "Transparenzkoeffizienten" << opacity_
    << " \n";
    
    return os;

}

std::ostream& operator << (std::ostream& os, Material const& material)
{
    return material.print(os);
}


