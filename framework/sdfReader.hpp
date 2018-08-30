#ifndef SDFREADER_HPP    
#define SDFREADER_HPP

#include "scene.hpp"

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

struct sdfReader
{
    Material SdfReader search_material_map(std::string const& search_name , Scene& scene);

    bool operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs);

    void read_sdf(std::string const& file_path , Scene& scene); 
};



#endif //SDFREADER_HPP