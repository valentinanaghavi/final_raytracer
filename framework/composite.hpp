#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "strike.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>


class Composite: public Shape
{
    public:
    Composite();
    Composite(std::string name);
    ~Composite();

    void add(std::shared_ptr<Shape>& shape) override;
    void remove(std::shared_ptr<Shape>& shape) override;
    void print(std::ostream os) const;

    std::vector<std::shared_ptr<Shape>> getComposite() override;

    inline bool intersect(Ray const& ray, float& t) const override
    {
        return true;
    }
    inline Strike intersection(Ray const& ray) const override
    {
        return Strike{};
    }

    /*void translate (glm::vec3 const& translate) override;
    void scale (glm::vec3 const& scale) override;
    void rotate (float phi, glm::vec3 const& achse) override;*/

    private:
    std::string name_;
    std::vector<std::shared_ptr<Shape>> shapes_;
};
#endif