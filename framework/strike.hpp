#ifndef STRIKE_HPP
#define STRIKE_HPP

#include <glm/glm.hpp>
#include <memory>
//#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
class Shape; //???

struct Strike 
{
    bool hit;
    float distance;
    glm::vec3 origin {0, 0, 0};
    glm::vec3 normal {0, 0, 0};
    //Shape* nearestShape;
    std::shared_ptr<Shape> nearestShape;
    
    Strike():
      hit{false},
      distance{INFINITY}, //distance für Kamera bei 401 x 401 -> 400, beim Strahl aber länger um Objekte zu treffen (gleich der Tiefe?)
      origin{glm::vec3(0.0f, 0.0f, 0.0f)},
      normal{glm::vec3(0.0f, 0.0f, 0.0f)}, //Normale die wenn es einen Treffer gibt vom Schnittpunkt abgeht (fürs spiegeln)
      nearestShape{nullptr}
      {}

    Strike(bool h, float d, glm::vec3 const& o, glm::vec3 const& n, std::shared_ptr<Shape> s): //Shape*s zu shared ptr
      hit{h},
      distance{d},
      origin{o},
      normal{n},
      nearestShape{s}
      {}

    Strike(std::shared_ptr<Shape> const& s):
      hit{false},
      distance{INFINITY},
      origin{glm::vec3(INFINITY)},
      normal{glm::vec3(INFINITY)},
      nearestShape{s}
      {}

};

#endif