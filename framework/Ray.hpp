#ifndef RAY_HPP
#define RAY_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

struct Ray
{
    glm::vec3 origin = {0.0f , 0.0f , 0.0f };
    glm::vec3 direction = {0.0f , 0.0f , -1.0f };

    Ray():
    origin(0.0f, 0.0f, 0.0f),
    direction(1.0f, 0.0f, 0.0f)
    {};

    Ray (glm::vec3 const& origin_, glm::vec3 const& direction_):
    origin(origin_),
    direction(direction_)
    {};

    Ray transformRay(glm::mat4 const& mat , Ray const& ray)
    {
        glm::vec4 ori{ray.origin , 1.0f}; //niemals or nennen :))
        glm::vec4 diri{ray.direction , 0.0f};
        
        glm::vec3 trans_Origin(mat * ori);
        glm::vec3 trans_Direction(mat * diri);

        return Ray {trans_Origin , trans_Direction};
    };
};

#endif //define RAY_HPP