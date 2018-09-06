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
#include "camera.hpp"
#include "sdfReader.hpp"

struct Scene
{
    std::map <std::string , Material> material_map;
    std::vector <std::shared_ptr<Shape>> shape_vector;
    std::vector <std::shared_ptr<Ambient>> ambient_vector;
    std::vector <std::shared_ptr<Light>> light_vector;
    std::vector <std::shared_ptr<Camera>> camera_vector;
    
    Camera camera;
    unsigned width;
    unsigned height;
    std::string filename;
};



#endif //SCENE_HPP