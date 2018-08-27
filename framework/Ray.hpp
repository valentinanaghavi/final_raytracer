#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

struct Ray
{
    glm::vec3 origin = {0.0f , 0.0f , 0.0f };
    glm::vec3 direction = {0.0f , 0.0f , -1.0f };

    Ray():
    origin(0.0f, 0.0f, 0.0f),
    direction(1.0f, 0.0f, 0.0f)
    {}

    Ray (glm::vec3 const& origin_, glm::vec3 const& direction_):
    origin(origin_),
    direction(direction_)
    {}
};

#endif //define RAY_HPP