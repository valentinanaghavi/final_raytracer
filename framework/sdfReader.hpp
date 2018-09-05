#ifndef SDFREADER_HPP    
#define SDFREADER_HPP

#include "scene.hpp"

#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "strike.hpp"
#include "shape.hpp"
#include "light.hpp"
#include "color.hpp"
#include "ambient.hpp"
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
#include <algorithm>
#include <fstream> //Stream class to both read and write from/to files
#include <memory> //manage dynamic shared_ptr

struct SdfReader
{
    Material search_material_map(std::string const& search_name , Scene& scene);
    void read_sdf(std::string const& file_path , Scene& scene); 
    glm::mat4 translation(glm::vec3 trans_vec) ;
    glm::mat4 inverse_translation(glm::vec3 trans_vec) ;
    glm::mat4 scale(glm::vec3 scale_vec) ;
    glm::mat4 rotation(glm::vec3 rotation_vec, float winkel) ;

    //bool operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs);

};



#endif //SDFREADER_HPP