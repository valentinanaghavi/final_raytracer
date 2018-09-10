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

/*float Box :: area() const //abstrakte M. = rein virtuelle Methode
    {
        glm::vec3 diffVec = max_ - min_ ;
        return 2*( diffVec.x * diffVec.y + diffVec.x * diffVec.z + diffVec.y * diffVec.z) ; //std::abs
    }

float Box :: volume() const
    {
        glm::vec3 diffVec = max_ - min_ ;
        return diffVec.x * diffVec.y * diffVec.z ;
    }*/

std::ostream& Box :: print(std::ostream& os ) const
    {
        Shape::print(os);
        os << /*"area: " << area() << " \n volume: " << volume() << " \n */"minimum: (" << min_.x << ", " << min_.y << ", " << min_.z << ") \n maximum: (" << max_.x << ", " << max_.y << ", " << max_.z << ")" << " \n";
        
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

/*Strike Box::intersection(Ray const& ray_intersect, float& t) const
{
    auto pointer = std::make_shared<Box>(*this);
    Strike strike(pointer);

    auto ray = transformRay (getWorld_trans_inv(), ray_intersect);

    Ray normalRay {ray.origin, ray.direction};
    normalRay.direction = glm::normalize(ray.direction);

    glm::vec3 invers{1.0f / normalRay.direction.x,
        1.0f / normalRay.direction.y,
        1.0f / normalRay.direction.z};

    float t1 = (getMin().x - normalRay.origin.x) * invers.x;
    float t2 = (getMax().x - normalRay.origin.x) * invers.x;
    float t_min = std::min(t1, t2); //Returns the smaller of a and b. 
    float t_max = std::max(t1, t2);

     t1 = (getMin().y - normalRay.origin.y) * invers.y;
     t2 = (getMax().y - normalRay.origin.y) * invers.y;
     t_min = std::max(t_min ,std::min(t1, t2)); 
     t_max = std::min(t_max ,std::max(t1, t2));

     t1 = (getMin().z - normalRay.origin.z) * invers.z;
     t2 = (getMax().z - normalRay.origin.z) * invers.z;
     t_min = std::max(t_min ,std::min(t1, t2)); 
     t_max = std::min(t_max ,std::max(t1, t2));

    if (t_max > std::max(t_min, 0.0f))
    {
        strike.hit = true;
        strike.distance = sqrt(t_min* t_min * 
                          (normalRay.direction.x * normalRay.direction.x + 
                            normalRay.direction.y * normalRay.direction.y+
                            normalRay.direction.z * normalRay.direction.z));

        glm::vec3 intersection_ray {ray_intersect.origin.x + strike.distance * normalRay.direction.x, //intersection zu intersection_ray geaendert
                                ray_intersect.origin.y + strike.distance * normalRay.direction.y,
                                ray_intersect.origin.z + strike.distance * normalRay.direction.z};
        
        
        strike.origin = intersection_ray;

        //Seite der Box finden wo der Strike seinen Ursprung hat
        if((strike.origin.x) == Approx(getMin().x))
        {
            strike.normal = glm::vec3{-1.0f, 0.0f, 0.0f};
        }
        else if((strike.origin.x) == Approx(getMax().x))
        {
            strike.normal = glm::vec3{1.0f, 0.0f, 0.0f};
        }
        else if((strike.origin.y) == Approx(getMin().y))
        {
            strike.normal = glm::vec3{0.0f, -1.0f, 0.0f};
        }
        else if((strike.origin.y) == Approx(getMax().y))
        {
            strike.normal = glm::vec3{0.0f, 1.0f, 0.0f};
        }
        else if((strike.origin.z) == Approx(getMin().z))
        {
            strike.normal = glm::vec3{0.0f, 0.0f, -1.0f};
        }
        else if((strike.origin.z) == Approx(getMax().z))
        {
            strike.normal = glm::vec3{0.0f, 0.0f, 1.0f};
        }

        glm::mat4 transposed = glm::transpose(getWorld_trans_inv());
        glm::vec3 transformedNormale(transposed * glm::vec4{strike.normal, 0.0f});
        strike.normal = glm::normalize(transformedNormale);

        return strike;
    }
    else
    {
        return strike;
    }
}
*/
Strike Box::intersection(Ray const& ray_in) const
{
    auto ptr = std::make_shared<Box>(*this);
    Strike strike (ptr);

    auto ray = transformRay(getWorld_trans_inv(), ray_in);

    Ray nray {ray.origin,ray.direction};
    nray.direction = glm::normalize(ray.direction);

    glm::vec3 invers{1.0f / nray.direction.x,
        1.0f / nray.direction.y,
        1.0f / nray.direction.z};
    //t = (x_min - p_0.x ) / d_x   || P_0.x : Ursprung vom Strahl , d_x : direction.x
    float t0 = (getMin().x - nray.origin.x) * invers.x;
    float t1 = (getMax().x - nray.origin.x) * invers.x;
    float tmin = std::min(t0, t1);
    float tmax = std::max(t0, t1);
    //std::cout << "min: " << tmin << std::endl;
    //std::cout << "max: " << tmax << std::endl;

    t0 = (getMin().y - nray.origin.y) * invers.y;
    t1 = (getMax().y - nray.origin.y) * invers.y;
    tmin = std::max(tmin, std::min(t0, t1));
    tmax = std::min(tmax, std::max(t0, t1));
    //std::cout << "min: " << tmin << std::endl;
    //std::cout << "max: " << tmax << std::endl;

    t0 = (getMin().z - nray.origin.z) * invers.z;
    t1 = (getMax().z - nray.origin.z) * invers.z;
    tmin = std::max(tmin, std::min(t0, t1));
    tmax = std::min(tmax, std::max(t0, t1));
    //std::cout << "min: " << tmin << std::endl;
    //std::cout << "max: " << tmax << std::endl;

    if(tmax > std::max(tmin, 0.0f))
    {
        strike.hit = true;
        strike.distance = sqrt(tmin * tmin *
                (nray.direction.x * nray.direction.x + 
                nray.direction.y * nray.direction.y + 
                nray.direction.z * nray.direction.z));
       
        glm::vec3 intersect_1
            {ray_in.origin.x + strike.distance * nray.direction.x,
            ray_in.origin.y + strike.distance * nray.direction.y,
            ray_in.origin.z + strike.distance * nray.direction.z};
       
        strike.origin = intersect_1;
    

        //finds the side of the box where the ray intersects and gets normale
        if((strike.origin.x) == Approx(getMin().x))
        {
           strike.normal = glm::vec3{-1.0f, 0.0f, 0.0f};
        }
        else if((strike.origin.x) == Approx(getMax().x))
        {
            strike.normal = glm::vec3{1.0f, 0.0f, 0.0f};
        }
        else if((strike.origin.y) == Approx(getMin().y))
        {
            strike.normal = glm::vec3{0.0f, -1.0f, 0.0f};
        }
        else if((strike.origin.y) == Approx(getMax().y))
        {
            strike.normal = glm::vec3{0.0f, 1.0f, 0.0f};
        }
        else if((strike.origin.z) == Approx(getMin().z))
        {
            strike.normal = glm::vec3{0.0f, 0.0f, -1.0f};
        }
        else if((strike.origin.z) == Approx(getMax().z))
        {
            strike.normal = glm::vec3{0.0f, 0.0f, 1.0f};
        }

        glm::mat4 transposed = glm::transpose(getWorld_trans_inv());
        glm::vec3 transformedNormale(transposed * glm::vec4{strike.normal, 0.0f});
        strike.normal = glm::normalize(transformedNormale);

        return strike;

    }
    else
    {
        return strike;
    }
}
