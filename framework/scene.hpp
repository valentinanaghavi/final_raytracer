#ifndef SCENE_HPP    
#define SCENE_HPP

#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "light.hpp"
#include "color.hpp"
#include "ambient.hpp"
#include "camera.hpp"

#include <map>
#include <vector>
#include <set>

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream> //Stream class to both read and write from/to files
#include <memory> //manage dynamic shared_ptr

struct Scene
{
    std::map <std::string , Material> material_map;
    std::vector <std::shared_ptr<Shape>> shape_vector;
    std::vector <std::shared_ptr<Ambient>> ambient_vector;
    std::vector <std::shared_ptr<Light>> light_vector;
    std::vector <std::shared_ptr<Camera>> camera_vector;

};



#endif //SCENE_HPP