#ifndef STRIKE_HPP
#define STRIKE_HPP

#include <glm/glm.hpp>

class Shape; //???

struct Strike 
{
    Strike():
    hit(false),
    distance(100000.0f), //distance für Kamera bei 401 x 401 -> 400, beim Strahl aber länger um Objekte zu treffen (gleich der Tiefe?)
    origin(glm::vec3(0.0f, 0.0f, 0.0f)),
    normal(glm::vec3(0.0f, 0.0f, 0.0f)), //Normale die wenn es einen Treffer gibt vom Schnittpunkt abgeht (fürs spiegeln)
    shape(nullptr)
    {}

    Strike(bool h, float d, glm::vec3 const& o, glm::vec3 const& n, Shape* s):
    hit(h),
    distance(d),
    origin(o),
    normal(n),
    shape(s)
    {}

    bool hit = false;
    float distance = 100000.0f;
    glm::vec3 origin {0, 0, 0};
    glm::vec3 normal {0, 0, 0};
    Shape* shape(nullptr);
};

#endif