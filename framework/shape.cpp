#include "shape.hpp"

Shape :: Shape():
    name_{"NoName"},
    material_{Material{}}
    {
       // std::cout << "default C'tor class Shape" << std::endl ;
    };

Shape :: Shape(std::string const& name , Material const& material):
    name_{name},
    material_{material}
    {
       // std::cout << "Constructor class Shape" << std::endl ;
    };

Shape :: ~Shape()
    {
      //  std::cout << "Destructor class Shape" << std::endl ;
    };


void Shape :: setName(std::string name) 
    {
        name_ = name ;
    }
void Shape :: setMaterial(Material material) 
    {
        material_ = material ;
    }
void Shape :: setWorld_trans(glm::mat4 world_transformation)
    {
        world_transformation_ = world_transformation;
    }
void Shape ::setWorld_trans_inv(glm::mat4 world_transformation_inv)
   {
       world_tranformation_inv_ = world_tranformation_inv;
   }

std::string Shape :: getName() const
    {
        return name_ ;
    }
Material Shape :: getMaterial() const
    {
        return material_ ;
    }
glm::mat4 Shape :: getWorld_trans() const
    {
        return world_transformation_ ;
    }
glm::mat4 Shape :: getWorld_trans_inv() const
    {
        return world_tranformation_inv_;
    }

std::ostream& Shape::print(std::ostream& os) const
	{
		os << "new shape: \n" << "name: " << name_ << " \n Material: " << material_ << "\n";
		return os;
	}

std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		return s.print(os);
    }

std::ostream& operator<<(std::ostream& os, std::shared_ptr<Shape> const& s)
    {
        return s->print(os);
    }

