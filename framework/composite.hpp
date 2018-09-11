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
        Strike nearestStrike;

        for(std::shared_ptr<Shape> s : shapes_)
        {
            Strike strike  = s -> intersection(ray);

            if(strike.hit == true && strike.distance < nearestStrike.distance)
            {
                nearestStrike = strike;
            }
        }
        return nearestStrike;
    }


    private:
    std::string name_;
    std::vector<std::shared_ptr<Shape>> shapes_;
};
#endif