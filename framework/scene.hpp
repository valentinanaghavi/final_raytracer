#ifndef SCENE_HPP    
#define SCENE_HPP

#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "light.hpp"
#include "color.hpp"
#include "camera.hpp"

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <map>
#include <vector>
#include <set>

#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream> //Stream class to both read and write from/to files
#include <memory> //manage dynamic shared_ptr


struct Scene
{

    void read_sdf(std::string const& file_path);

    std::map <std::string , Material> material_map;
    std::vector <std::shared_ptr<Shape>> shape_vector;
   //std::shared_ptr<Color> ambient_;
    std::vector <std::shared_ptr<Light>> light_vector;
    
    Color ambient_;
    Camera camera_;
    unsigned width_;
    unsigned height_;
    std::string filename_;



};

glm::mat4 translation(glm::vec3 trans_vec);
glm::mat4 inverse_translation(glm::vec3 trans_vec);
glm::mat4 scale(glm::vec3 scale_vec);
glm::mat4 rotation(glm::vec3 rotation_vec, float winkel) ; //Winkel in Bogenmaß !!

std::shared_ptr<Shape> search_shape_vector(std::string const& search_name , std::vector <std::shared_ptr<Shape>> shape_container);

bool operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs);

#endif //SCENE_HPP