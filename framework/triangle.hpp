#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/geometric.hpp>
#include <glm/gtx/intersect.hpp>
#include <string>

#include "shape.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "Ray.hpp"
#include "strike.hpp"


class Triangle: public Shape
{
    public:
    Triangle(glm::vec3 p_1, glm::vec3 p_2, glm::vec3 p_3);
    Triangle(std::string const& name, Material const& material, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);
    ~Triangle();

    Strike intersection(Ray const& ray) const override;

    private:
    glm::vec3 p1_;
    glm::vec3 p2_;
    glm::vec3 p3_;
    std::string name_;
    Material material_;

    glm::vec3 normalenVektor_;

};

#endif