#include "sdfReader.hpp"

Material SdfReader :: search_material_map(std::string const& search_name , Scene& scene)
{
    auto it = scene.material_map.find(search_name);
    if(it == scene.material_map.end())
    {
        std::cout << "Der Name existiert nicht. \n";
       // Material mat =  Material ();
        return Material ();
    }
    else
    {
        std::cout << "Der Name existiert. \n";
        return it->second;
    }
};


void SdfReader :: read_sdf(std::string const& file_path , Scene& scene) 
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

                //std::shared_ptr<Material> material_path = std::make_shared<Material>(material);
                scene.material_map[material.name_] = material;
                //scene.material_map.insert(std::make_pair(material_path->name_ , material_path));
                //scene.material_set.insert(material_path);
                //scene.material_vector.push_back(material_path);
               // scene.material_map.insert(std::pair<std::string,std::shared_ptr<Material>> (material_path->name_,material_path));
                }

                if(b=="shape")
                {
                    if (c=="box")
                    {
                       Box box;
                       std::string name , materialname;
                       glm::vec3 min , max ;

                       buffer >> a;
                       buffer >> b;
                       buffer >> name;
                       buffer >> min.x;
                       buffer >> min.y;
                       buffer >> min.z;
                       buffer >> max.x;
                       buffer >> max.y;
                       buffer >> max.z;
                       buffer >> materialname;

                     //ueberpruefen , ob materialname in der sdf existiert bzw gespeichert wurde
                       Material mat_test = search_material_map(materialname , scene) ;
                       if (mat_test.name_.compare("no Name") == 0)
                       {
                           std::cout << "Der Materialname existiert nicht. Die Sphere kann nicht bearbeitet werden. \n";
                       }
                       else
                       {
                           Material material = scene.material_map[materialname];

                           std::shared_ptr<Shape> box_path = std::make_shared<Box>(min , max , name , material);
                           scene.shape_vector.push_back(box_path);
                       }

                    }

                    if (c=="sphere")
                    {
                       Sphere sphere;
                       std::string name , materialname;
                       float radius;
                       glm::vec3 center;
                       
                       buffer >> a;
                       buffer >> b;
                       buffer >> name;
                       buffer >> center.x;
                       buffer >> center.y;
                       buffer >> center.z;
                       buffer >> radius;
                       buffer >> materialname;
                       
                       //ueberpruefen , ob materialname in der sdf existiert bzw gespeichert wurde
                       Material mat_test = search_material_map(materialname , scene) ;
                       if (mat_test.name_.compare("no Name") == 0)
                       {
                           std::cout << "Der Materialname existiert nicht. Die Sphere kann nicht bearbeitet werden. \n";
                       }
                       else
                       {
                           Material material = scene.material_map[materialname];

                           std::shared_ptr<Shape> sphere_path = std::make_shared<Sphere>(center , radius , name , material);
                           scene.shape_vector.push_back(sphere_path);
                       }
                    }

                }
                else if (b == "light")
                {
                    Light light;
                    std::string name;
                    glm::vec3 pos;
                    Color color;
                    float brightness;

                    buffer >> a;
                    buffer >> b;
                    buffer >> name;
                    buffer >> pos.x;
                    buffer >> pos.y;
                    buffer >> pos.z;
                    buffer >> color.r;
                    buffer >> color.g;
                    buffer >> color.b;
                    buffer >> brightness;
    
                    std::shared_ptr<Light> light_path = std::make_shared<Light>(name , pos , color , brightness );
                    scene.light_map.insert(std::pair<std::string,std::shared_ptr<Light>> (light_path->name_, light_path));

                }
            }
            else if (a == "ambient")
            {
                    Color color;

                    buffer >> a;
                    buffer >> color.r;
                    buffer >> color.g;
                    buffer >> color.b;

                    std::shared_ptr<Ambient> ambient_path = std::make_shared<Ambient>(color);
                    scene.ambient_vector.push_back(ambient_path);
            }
            else if (a == "camera")
            {
                    std::string name;
                    float fovX;

                    buffer >> a;
                    buffer >> name;
                    buffer >> fovX;


                    std::shared_ptr<Camera> camera_path = std::make_shared<Camera>(name , fovX);
                    scene.camera_vector.push_back(camera_path);
            }

        }
        myfile.close();
    

};



bool SdfReader :: operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs)
{
    return lhs->name_ < rhs->name_ ;
};

