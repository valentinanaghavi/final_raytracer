#include "triangle.hpp"

//https://www.uninformativ.de/bin/RaytracingSchnitttests-76a577a-CC-BY.pdf
//https://wwwcg.in.tum.de/fileadmin/user_upload/Lehrstuehle/Lehrstuhl_XV/Teaching/SS07/Proseminar/Florian_Ferstl.pdf

Triangle::Triangle(glm::vec3 p_1, glm::vec3 p_2, glm::vec3 p_3):
Shape{},
p1_{p_1},// im Uhrzeigersinn angeben
p2_{p_2},
p3_{p_3}
{
    normalenVektor_ = glm::normalize(glm::cross(p2_ - p1_, p3_ -p1_));
}

Triangle::Triangle(std::string const& name, Material const& material, glm::vec3 p_1, glm::vec3 p_2, glm::vec3 p_3):
Shape{name_, material_},
p1_{p_1},
p2_{p_2},
p3_{p_3}
{
    normalenVektor_ = glm::normalize(glm::cross(p2_ - p1_, p3_ -p1_));
}

Triangle::~Triangle()
{}

bool Triangle :: intersect ( Ray const& ray , float& t ) const 
{
    std::cout << " intersect hat hier keine Verwendung \n";
    return false;
}
    

Strike Triangle::intersection(Ray const& rayTriangle) const
{
    auto ptr = std::make_shared<Triangle>(*this);
    Strike strike(ptr);

    Ray ray = transformRay(getWorld_trans_inv(), rayTriangle);
    float t = glm::dot(normalenVektor_, ray.direction);
    if (t != 0)
    {
        float distance = (-(normalenVektor_.x * (ray.origin.x - p1_.x))-(normalenVektor_.y *(ray.origin.y - p1_.y)) 
                         - (normalenVektor_.z *(ray.origin.z - p1_.z))) / t;

        if (distance > 0)
        {
            glm::vec3 objectStrike = ray.origin + (distance * ray.direction);

            strike.origin = objectStrike;

            
                if (glm::dot(p3_-p1_, p1_- strike.origin) <= glm::dot(p3_ - p1_, p2_ - p1_) && glm::dot(p1_ - p2_, p2_ - strike.origin) <= 
                glm::dot(p1_ - p2_, p3_ - p2_) && glm::dot(p2_ - p3_, p3_ - strike.origin) <= glm::dot(p2_ - p3_, p1_ - p3_))
                {
                    strike.origin = objectStrike;
                    strike.hit = true;
                    strike.normal = normalenVektor_;
                    strike.nearestShape = ptr;
                    strike.distance = distance;
                }

                glm::mat4 transposed = glm::transpose(getWorld_trans_inv());
                glm::vec3 transformedNormale(transposed * glm::vec4{strike.normal, 0.0f});
                strike.normal = glm::normalize(transformedNormale);
        }
    }
    return strike;
}
