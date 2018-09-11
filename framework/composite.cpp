#include "composite.hpp"

Composite::Composite()
{}

Composite::Composite(std::string name):
name_(name)
{}

Composite::~Composite()
{}

void Composite::add(std::shared_ptr<Shape>& shape)
{
    shapes_.push_back(shape);
}

void Composite::remove(std::shared_ptr<Shape>& shape)
{
    std::vector<std::shared_ptr<Shape>>::iterator it;

    for(it = shapes_.begin(); it != shapes_.end();)
    {
        if((*it) == shape)
        {
            it = shapes_.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Composite::print(std::ostream os) const
{
    for(auto s:shapes_)
    {
        s ->print(os);
    }
}

std::vector<std::shared_ptr<Shape>> Composite::getComposite()
{
    return shapes_;
}
