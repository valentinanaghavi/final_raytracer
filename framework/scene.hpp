#ifndef SCENE_HPP    // Valentina stinkt
#define SCENE_HPP

#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"

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
    std::vector<std::shared_ptr<Material>> material_vector;
    std::set<std::shared_ptr<Material>> material_set;
    std::map <std::string , std::shared_ptr<Material>> material_map;
};

//free function
void read_sdf(std::string const& file_path , Scene& scene) 
{
    std::ifstream myfile (file_path);
    std::string line;

    if(!myfile.is_open())
    {
        std::cout << "Unable to open file" ;
    }
    else
    {   
        std::cout << "Able to read file" ;

    }
        while( std::getline( myfile , line ))
        {
           
            std::stringstream buffer(line);
            std::string a;
            std::string b;
            std::string c;
            std::string d;

            buffer >> a >> b >> c >> d;
            
            if(a=="define")

            {
                if(b=="material")
                {
                    
                Material material;

                buffer 
                >> a
                >> b
                >> material.name_
                >> material.ka_.r
                >> material.ka_.g
                >> material.ka_.b
                >> material.kd_.r
                >> material.kd_.g
                >> material.kd_.b
                >> material.ks_.r
                >> material.ks_.g
                >> material.ks_.b
                >> material.m_;

                std::shared_ptr<Material> material_path = std::make_shared<Material>(material);

                //scene.material_map.insert(std::make_pair(material_path->name_ , material_path));
                //scene.material_set.insert(material_path);
                //scene.material_vector.push_back(material_path);
                scene.material_map.insert(std::pair<std::string,std::shared_ptr<Material>> (material_path->name_,material_path));
                }

                if(b=="shape")
                {
                    if (c=="box")
                    {
                       Box box;
                       std::string name , materialname;
                       float minx , miny , minz , maxx , maxy , maxz;
                    
                       buffer >> a;
                       buffer >> b;
                       buffer >> name;
                       buffer >> minx;
                       buffer >> miny;
                       buffer >> minz;
                       buffer >> maxx;
                       buffer >> maxy;
                       buffer >> maxz;
                       buffer >> materialname;

                      /* box.setName(name);
                       box.setMin(minx).x;
                       box.setMin(miny).y;
                       box.setMin(minz).z;
                       box.setMax(maxx).x;
                       box.setMax(maxy).y;
                       box.setMax(maxz).z;
                       box.setMaterial(material);*/
                    }

                    if (c=="sphere")
                    {
                       Sphere sphere;
                       std::string name , materialname;
                       float cx , cy , cz , radius ;
                       
                       
                       buffer >> a;
                       buffer >> b;
                       buffer >> name;
                       buffer >> cx;
                       buffer >> cy;
                       buffer >> cz;
                       buffer >> radius;
                       buffer >> materialname;

                       /*sphere.setName(name);
                       sphere.setCenter(cx).x;
                       sphere.setCenter(cy).y;
                       sphere.setCenter(cz).z;
                       sphere.setRadius(radius);
                       sphere.setMaterial(material);*/
                    }

                }
            }

        }
        myfile.close();
    

}



bool operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs)
{
    return lhs->name_ < rhs->name_ ;
}

/*std::shared_ptr<Material> search_vector(std::string const& search_name , std::vector<std::shared_ptr<Material>> const& material_vector_)
{
    auto it = std::find_if(material_vector_.begin() , material_vector_.end(),[search_name](std::shared_ptr<Material> const& material)
    {
       return material->name_ == search_name ;
    });

    if (it == material_vector_.end())
    {
        std::cout << "Der Name existiert nicht. \n";
        return nullptr;
    }
    else
    {
        std::cout << "Der Name ist an Stelle:" << *(*it) << "\n";
        return *it;
    }
};

std::shared_ptr<Material> search_map(std::string const& search_name , std::map <std::string, std::shared_ptr <Material> > const& material_map_)
{
    auto it = material_map_.find(search_name);
    if(it == material_map_.end())
    {
        std::cout << "Der Name existiert nicht. \n";
        return nullptr;
    }
    else
    {
        std::cout << "Der Name ist an Stelle:" << *it->second << "\n";
        return it->second;
    }
};

std::shared_ptr<Material> search_set(std::string const& search_name , std::set<std::shared_ptr<Material>> const& material_set_)
{
    auto it = std::find_if(material_set_.begin() , material_set_.end(),[search_name](std::shared_ptr<Material> const& material)
    {
       return material->name_ == search_name ;
    });
    if(it == material_set_.end())
    {
        std::cout << "Der Name existiert nicht. \n";
        return nullptr;
    }
    else
    {
        std::cout << "Der Name ist an Stelle:" << *(*it) << "\n";
        return *it;
    }
};*/

std::shared_ptr<Material> find_material(std::string matName, Scene& sc)
{
    if(sc.material_map.find(matName) != sc.material_map.end())
    {
        return sc.material_map.find(matName)->second;
        
    }
    else 
    {
        return nullptr;
    }
}
#endif //SCENE_HPP