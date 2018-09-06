#include "box.hpp"

#include <iostream>
#include <string>
#include <math.h>
#include <glm/vec3.hpp>

Box :: Box(glm::vec3 const& min  , glm::vec3 const& max , std::string const& name, Material const& material):
    Shape(name , material),
    min_{min},
    max_{max}
    {};

Box :: Box () :
    Shape(),
    min_{0.0 , 0.0 , 0.0},
    max_{0.0 , 0.0 , 0.0}
    {};

Box :: ~Box()
    {};

void Box :: setMax(glm::vec3 max) 
    {
        max_ = max ;
    }

void Box :: setMin(glm::vec3 min) 
    {
        min_ = min ;
    }


glm::vec3 Box :: getMax() const 
    {
        return max_ ;
    }

glm::vec3  Box :: getMin() const
    {
        return min_ ;
    }

float Box :: area() const //abstrakte M. = rein virtuelle Methode
    {
        glm::vec3 diffVec = max_ - min_ ;
        return 2*( diffVec.x * diffVec.y + diffVec.x * diffVec.z + diffVec.y * diffVec.z) ; //std::abs
    }

float Box :: volume() const
    {
        glm::vec3 diffVec = max_ - min_ ;
        return diffVec.x * diffVec.y * diffVec.z ;
    }

std::ostream& Box :: print(std::ostream& os ) const
    {
        Shape::print(os);
        os << "area: " << area() << " \n volume: " << volume() << " \n minimum: (" << min_.x << ", " << min_.y << ", " << min_.z << ") \n maximum: (" << max_.x << ", " << max_.y << ", " << max_.z << ")" << " \n";
        
        return os;
    }


bool Box :: intersect( Ray const& ray , float& t ) const 
{
    float t_x_min;
    float t_x_max;
    float t_y_min;
    float t_y_max;
    float t_z_min;
    float t_z_max;

    if (ray.direction.x >= 0)
    {
        t_x_min = (min_.x -ray.origin.x) / ray.direction.x ;
        t_x_max = (max_.x -ray.origin.x) / ray.direction.x ;
    }
    else
    {
        t_x_min = (max_.x -ray.origin.x) / ray.direction.x ;
        t_x_max = (min_.x -ray.origin.x) / ray.direction.x ;
    }

    if (ray.direction.y >= 0)
    {
        t_y_min = (min_.y -ray.origin.y) / ray.direction.y ;
        t_y_max = (max_.y -ray.origin.y) / ray.direction.y ;
    }
    else
    {
        t_y_min = (max_.y -ray.origin.y) / ray.direction.y ;
        t_y_max = (min_.y -ray.origin.y) / ray.direction.y ;
    }

    if((t_x_min > t_y_max) || (t_y_min > t_x_max))
    {
        return false;
    }
        
    if(t_y_min > t_x_min)
    {
        t_x_min = t_y_min;
    }
    if(t_y_max < t_x_max)
    {
        t_x_max = t_y_max;        
    }

    if (ray.direction.z >= 0)
    {
        t_z_min = (min_.z -ray.origin.z) / ray.direction.z ;
        t_z_max = (max_.z -ray.origin.z) / ray.direction.z ;
    }
    else
    {
        t_z_min = (max_.z -ray.origin.z) / ray.direction.z ;
        t_z_max = (min_.z -ray.origin.z) / ray.direction.z ;
    }
    if((t_x_min >t_z_max) || (t_z_min > t_x_max))
    {
        return false;
    }
    if(t_z_min > t_x_min)
    {
        t_x_min = t_z_min;
    }
    if(t_z_max < t_x_min)
    {
        t_x_max = t_z_max;
    }
    return((t_x_min < 0 ) && (t_x_max > t));
}

Strike Box::intersection(Ray const& ray_intersect, float& t) const
{
    auto pointer = std::make_shared<Box>(*this);
    Strike strike(pointer);

    //auto ray = transform_ray (world_transformation_invers_, ray_intersect);

    Ray normalRay {ray_intersect.origin, ray_intersect.direction};
    normalRay.direction = glm::normalize(ray_intersect.direction);

    float t1 = (min_.x - normalRay.origin.x) / normalRay.direction.x;
    float t2 = (max_.x - normalRay.origin.x) / normalRay.direction.x;
    float t_min = std::min(t1, t2); //Returns the smaller of a and b. 
    float t_max = std::max(t1, t2);

     t1 = (min_.y - normalRay.origin.y) / normalRay.direction.y;
     t2 = (max_.y - normalRay.origin.y) / normalRay.direction.y;
     t_min = std::max(t_min ,std::min(t1, t2)); 
     t_max = std::min(t_max ,std::max(t1, t2));

     t1 = (min_.z - normalRay.origin.z) / normalRay.direction.z;
     t2 = (max_.z - normalRay.origin.z) / normalRay.direction.z;
     t_min = std::max(t_min ,std::min(t1, t2)); 
     t_max = std::min(t_max ,std::max(t1, t2));

    if (t_max > std::max(t_min, 0.0f))
    {
        strike.hit = true;
        strike.distance = sqrt(sqrt(t_min) * (sqrt(normalRay.direction.x) + 
                         sqrt(normalRay.direction.y) + sqrt(normalRay.direction.z)));

        glm::vec3 intersection_ray {ray_intersect.origin.x + strike.distance * normalRay.direction.x, //intersection zu intersection_ray geaendert
                                ray_intersect.origin.y + strike.distance * normalRay.direction.y,
                                ray_intersect.origin.z + strike.distance * normalRay.direction.z};
        
        
        strike.origin = intersection_ray;

        //Seite der Box finden wo der Strike seinen Ursprung hat
        if((strike.origin.x) == Approx(min_.x))
        {
            strike.normal = glm::vec3{-1.0f, 0.0f, 0.0f};
        }
        else if((strike.origin.x) == Approx(max_.x))
        {
            strike.normal = glm::vec3{1.0f, 0.0f, 0.0f};
        }
        else if((strike.origin.y) == Approx(min_.y))
        {
            strike.normal = glm::vec3{0.0f, -1.0f, 0.0f};
        }
        else if((strike.origin.y) == Approx(max_.y))
        {
            strike.normal = glm::vec3{0.0f, 1.0f, 0.0f};
        }
        else if((strike.origin.z) == Approx(min_.z))
        {
            strike.normal = glm::vec3{0.0f, 0.0f, -1.0f};
        }
        else if((strike.origin.z) == Approx(max_.z))
        {
            strike.normal = glm::vec3{0.0f, 0.0f, 1.0f};
        }

        //glm::mat4 transposed = glm::transpose(world_transformatio_inv);
        //glm::vec3 transformedNormale(transposed * glm::vec4{strike.normal, 0.0f});
        //strike.normal = glm::normalize(transformedNormale);

        return strike;
    }
    else
    {
        return strike;
    }
}

