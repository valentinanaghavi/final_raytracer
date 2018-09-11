#include "scene.hpp"

void Scene :: read_sdf(std::string const& file_path) //, Scene& scene) 
{
    std::ifstream file;
    file.open (file_path, std::ifstream::in);
    //myfile.open(file_path);
    std::string line;
    Scene scene;
    //file.open(file_path, std::ios::in);
    std::cout << "loadScene (openFile): " << file_path << std::endl;
    if(file.is_open())
    {
        std::cout << "Able to read file \n" ;
    }
    else
    {   
        std::cout << "Unable to open file \n" ;        

    }
        while( std::getline( file , line ))
        {
           
            std::stringstream buffer(line);
            std::string word ;

            buffer<<line;
            buffer >> word;
            
            if(word=="define")
            {
                    buffer >> word;

                    if(word=="material")
                    {

                        Material material; 

                        buffer >> material.name_;
                        buffer >> material.ka_.r;
                        buffer >> material.ka_.g;
                        buffer >> material.ka_.b;
                        buffer >> material.kd_.r;
                        buffer >> material.kd_.g;
                        buffer >> material.kd_.b;
                        buffer >> material.ks_.r;
                        buffer >> material.ks_.g;
                        buffer >> material.ks_.b;
                        buffer >> material.m_;
                        buffer >> material.refract_;
                        buffer >> material.opacity_;

                //std::shared_ptr<Material> material_path = std::make_shared<Material>(material);
                        material_map[material.name_] = material;
                        std::cout << "new material added:" << material.name_ << "\n";
                //material_map.insert(std::make_pair(material_path->name_ , material_path));
                //material_set.insert(material_path);
                //material_vector.push_back(material_path);
               // material_map.insert(std::pair<std::string,std::shared_ptr<Material>> (material_path->name_,material_path));
                    }

                    if(word=="shape")
                    {
                        buffer >> word ;
                        if (word=="box")
                        {
                            std::string name , materialname;
                            glm::vec3 min , max ;

                            buffer >> name;
                            buffer >> min.x;
                            buffer >> min.y;
                            buffer >> min.z;
                            buffer >> max.x;
                            buffer >> max.y;
                            buffer >> max.z;
                            buffer >> materialname;

                     
                            Material material = material_map[materialname];

                            std::shared_ptr<Shape> box_path = std::make_shared<Box>(min , max , name , material);
                            shape_vector.push_back(box_path);
                            
                            std::cout << "new box added:"  << name << "\n";;
                        }

                        else if (word=="sphere")
                        {
                       //Sphere sphere;
                            std::string name , materialname;
                            float radius;
                            glm::vec3 center;
                       
                            buffer >> name;
                            buffer >> center.x;
                            buffer >> center.y;
                            buffer >> center.z;
                            buffer >> radius;
                            buffer >> materialname;
                       
        
                            Material material = material_map[materialname];

                            std::shared_ptr<Shape> sphere_path = std::make_shared<Sphere>(center , radius , name , material);
                            shape_vector.push_back(sphere_path);
                            
                            std::cout << "new sphere added:" << name << "\n";
                        }
                        else if (word=="triangle")
                        {
                            std::string name , materialname;
                            glm::vec3 p1,p2,p3;
                       
                            buffer >> name;
                            buffer >> p1.x;
                            buffer >> p1.y;
                            buffer >> p1.z;
                            buffer >> p2.x;
                            buffer >> p2.y;
                            buffer >> p2.z;         
                            buffer >> p3.x;
                            buffer >> p3.y;
                            buffer >> p3.z;                       
                            buffer >> materialname;
                       
        
                            Material material = material_map[materialname];

                            std::shared_ptr<Shape> triangle_path = std::make_shared<Triangle>( name , material, p1 , p2, p3);
                            shape_vector.push_back(triangle_path);
                            
                            std::cout << "new triangle added:" << name << "\n";
                        }
                        else if (word=="composite")
                        {
                            std::string name , nameShape;

                            buffer >> name;
                        
                            std::shared_ptr <Composite> composite = std::make_shared<Composite>(name);
                            composite_ = composite;
                            std::shared_ptr<Shape> newShape;

                            while (!buffer.eof())
                            {
                                buffer >> nameShape ;

                                for (std::shared_ptr<Shape> s : shape_vector)
                                {
                                    if(s-> getName() == nameShape)
                                    {
                                        newShape = s ;
                                    }
                                }
                                if(!newShape)
                                {
                                    std::cout<< " Shape not found ! \n";
                                    
                                }
                                else
                                {
                                std::cout<< "Composite :" << nameShape << "\n";
                                composite_ -> add(newShape);
                                }
                            }


                        }

                    }

                    else if (word == "light")
                    {
                        std::string name;
                        glm::vec3 pos;
                        Color color;
                        float brightness;


                        buffer >> name;
                        buffer >> pos.x;
                        buffer >> pos.y;
                        buffer >> pos.z;
                        buffer >> color.r;
                        buffer >> color.g;
                        buffer >> color.b;
                        buffer >> brightness;
    
                        std::shared_ptr<Light> light_path = std::make_shared<Light>(name , pos , color , brightness );
                    //    light_map.insert(std::pair<std::string,std::shared_ptr<Light>> (light_path->name_, light_path));
                        light_vector.push_back(light_path);
                        std::cout << "new light added:" << name << "\n";

                    }
            
                    else if (word == "ambient")
                    {
                        Color color;

                        buffer >> color.r;
                        buffer >> color.g;
                        buffer >> color.b;

                       // std::shared_ptr<Ambient> ambient = std::make_shared<Ambient>(color);
                        //ambient_vector.push_back(ambient_path);
                        //ambient_ = ambient;
                        ambient_ = color;
                        std::cout << "new ambient added \n";
                        //std::cout << "Ambient:\n" << *ambient << "\n";

                    }
                    else if (word == "camera")
                    {
                        Camera camera;

                        buffer >> camera.name_;
                        buffer >> camera.fovX_;
                        buffer >> camera.eye_.x;
                        buffer >> camera.eye_.y;
                        buffer >> camera.eye_.z;
                        buffer >> camera.direction_.x;
                        buffer >> camera.direction_.y;
                        buffer >> camera.direction_.z;
                        buffer >> camera.up_.x;
                        buffer >> camera.up_.y;
                        buffer >> camera.up_.z;
                   
                        camera_ = camera;
                        std::cout << "new camera added:" << camera_.name_ << "\n";

                }
            }
/***********************************DEFINE-END***************TRANSFORM-START***********************************************************/
            else if (word == "transform")
            {
                //fuer cam auch??
                    std::string shape_name;

                    buffer >> shape_name;
                    std::shared_ptr<Shape> foundShape = search_shape_vector( shape_name,    shape_vector ); 
                //auto foundShape = shape_vector.find(shape_name);

                    if(foundShape != nullptr)
                    {
                        buffer >> word ;

                        if(word == "scale")
                        {
                            glm::vec3 s;

                            buffer >> s.x;
                            buffer >> s.y;
                            buffer >> s.z;

                            glm::mat4 scale_mat = scale(s);
                            glm::mat4 trans_mat = foundShape -> getWorld_trans();
                            trans_mat *= scale_mat ;
                            foundShape -> setWorld_trans(trans_mat);
                            foundShape -> setWorld_trans_inv(glm::inverse(trans_mat));
                    
                        }
                        else if(word == "translate")
                        {
                            glm::vec3 t;

                            buffer >> t.x;
                            buffer >> t.y;
                            buffer >> t.z;

                            glm::mat4 translate_mat = translation(t);
                            glm::mat4 trans_mat = foundShape -> getWorld_trans();
                            trans_mat *= translate_mat ;
                            foundShape -> setWorld_trans(trans_mat);
                            foundShape -> setWorld_trans_inv(glm::inverse(trans_mat));

                        }
                        else if(word == "rotate")
                        {
                            float winkel;
                            glm::vec3 r;
                         
                            buffer >> winkel;
                            buffer >> r.x;
                            buffer >> r.y;
                            buffer >> r.z;
                        
                            glm::mat4 rotate_mat = rotation(r, winkel);
                            glm::mat4 trans_mat = foundShape -> getWorld_trans();
                            trans_mat *= rotate_mat ;
                            foundShape -> setWorld_trans(trans_mat);
                            foundShape -> setWorld_trans_inv(glm::inverse(trans_mat));
                        }
                        else
                        {
                            std::cout << "Transform Funktion kann nicht gelesen werden."<< std::endl;
                        }
                    }
                    else if (shape_name == camera_.name_)
                    {
                        buffer >> word ;

                        if(word == "scale")
                        {
                            glm::vec3 s;

                            buffer >> s.x;
                            buffer >> s.y;
                            buffer >> s.z;

                            glm::mat4 scale_mat = scale(s);
                            glm::mat4 trans_mat = camera_.world_transformation_;
                            trans_mat *= scale_mat ;
                            camera_.world_transformation_ =trans_mat;
                            camera_.world_transformation_inv_ = glm::inverse(trans_mat);
                    
                        }
                        else if(word == "translate")
                        {
                            glm::vec3 t;

                            buffer >> t.x;
                            buffer >> t.y;
                            buffer >> t.z;

                            glm::mat4 translate_mat = translation(t);
                            glm::mat4 trans_mat = camera_.world_transformation_;
                            trans_mat *= translate_mat ;
                            camera_.world_transformation_ =trans_mat;
                            camera_.world_transformation_inv_ = glm::inverse(trans_mat);

                        }
                        else if(word == "rotate")
                        {
                            float winkel;
                            glm::vec3 r;
                         
                            buffer >> winkel;
                            buffer >> r.x;
                            buffer >> r.y;
                            buffer >> r.z;
                        
                            glm::mat4 rotate_mat = rotation(r, winkel);
                            glm::mat4 trans_mat = camera_.world_transformation_;
                            trans_mat *= rotate_mat ;
                            camera_.world_transformation_ =trans_mat;
                            camera_.world_transformation_inv_ = glm::inverse(trans_mat);
                        }
                        else
                        {
                            std::cout << "Transform Funktion kann nicht gelesen werden."<< std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Befehl kann nicht ausgeführt werden."<< std::endl;
                        
                    }
            }
/***********************************TRANSFROM_END************RENDER-START**************************************************************/
            else if( word == "render")
            {   
                std::string cameraName;

                buffer >> cameraName;

                if (cameraName == camera_.name_)
                {
                    buffer >> filename_;
                    buffer >> width_;
                    buffer >> height_;

                /*width_ = width;
                height_ = height;
                filename_ = filename;*/
                    std::cout << "rendern des filenames " << cameraName << "," <<  width_  << "," <<  height_<< "," <<  filename_ << "\n";
                }
                else
                {
                    std::cout << "Kamera fuer das rendern nicht gefunden."<< std::endl;                    
                }

            }
        
        }
        file.close();


        std::cout <<"*************************************** "<< std::endl;
        //Ausgabe der Material Map und Shape Vector
        std::cout <<"\n" <<"Material Map: "<< std::endl;
        for(auto& mat : material_map)
        {
             std::cout << "[" << mat.first << "] \n";
        }
        std::cout <<"\n" <<"Shape Vector: "<< std::endl;
        for(auto it = shape_vector.cbegin(); it != shape_vector.cend(); ++it)
        {
            std::cout << *it << "\n";
        }
        std::cout <<"*************************************** "<< std::endl;
        //Ausgabe der Kamera Vector
        std::cout << "Camera:\n" << camera_ << "\n";
        std::cout <<"*************************************** "<< std::endl;
        //Ausgabe der Ambient
        std::cout << "Ambient:\n" << ambient_ << "\n";
        std::cout <<"*************************************** "<< std::endl;
        //Ausgabe Render Bedingungen
        std::cout << "Render Stuff:\n";
        std::cout << "filename: " << filename_ << "\n";
        std::cout << "width: " << width_ << "\n";
        std::cout << "height: " << height_ << "\n";
        std::cout <<"*************************************** "<< std::endl;


};


std::shared_ptr<Shape> search_shape_vector(std::string const& search_name , std::vector <std::shared_ptr<Shape>> shape_container)
{
    auto it = std::find_if(shape_container.begin() , shape_container.end(), [&search_name](std::shared_ptr<Shape> const& s){return (s ->getName()) == search_name;});

    if(it == shape_container.end())
    {
        std::cout << "Der Name existiert nicht. \n";
        return nullptr;
    }
    else
    {
        std::cout << "Die Shape existiert und kann transformiert werden. \n";
        return *it;
    }

}



glm::mat4 translation(glm::vec3 trans_vec)
{
    glm::mat4 trans_mat;

    trans_mat[0] = glm::vec4 {1.0f , 0.0f , 0.0f , 0.0f};
    trans_mat[1] = glm::vec4 {0.0f , 1.0f , 0.0f , 0.0f};
    trans_mat[2] = glm::vec4 {1.0f , 0.0f , 1.0f , 0.0f};
    trans_mat[3] = glm::vec4 {trans_vec , 1.0f};
    
    return trans_mat ;
}

glm::mat4 inverse_translation(glm::vec3 trans_vec)
{
    glm::mat4 trans_mat;

    trans_mat[0] = glm::vec4 {1.0f , 0.0f , 0.0f , 0.0f};
    trans_mat[1] = glm::vec4 {0.0f , 1.0f , 0.0f , 0.0f};
    trans_mat[2] = glm::vec4 {1.0f , 0.0f , 1.0f , 0.0f};
    trans_mat[3] = glm::vec4 {trans_vec *(-1.0f) , 1.0f};
    
    return trans_mat ;    
}

glm::mat4 scale(glm::vec3 scale_vec)
{
    glm::mat4 scale_mat;

    scale_mat[0] = glm::vec4 {scale_vec.x , 0.0f , 0.0f , 0.0f};
    scale_mat[1] = glm::vec4 {0.0f , scale_vec.y , 0.0f , 0.0f};
    scale_mat[2] = glm::vec4 {1.0f , 0.0f , scale_vec.z , 0.0f};
    scale_mat[3] = glm::vec4 {0.0f,  0.0f , 0.0f , 1.0f};
    
    return scale_mat ;   

} 

glm::mat4 rotation(glm::vec3 rotation_vec, float winkel) //Winkel in Bogenmaß !!
{
    glm::mat4 rotation_mat;

    if (rotation_vec.x == 1.0f) //Drehung um X-Achse
    {
        rotation_mat[0] =  glm::vec4 {1.0f , 0.0f , 0.0f , 0.0f};
        rotation_mat[1] =  glm::vec4 {0.0f , cos(winkel) , sin(winkel) , 0.0f};
        rotation_mat[2] =  glm::vec4 {0.0f , - sin(winkel) , cos(winkel) , 0.0f};
        rotation_mat[3] =  glm::vec4 {0.0f , 0.0f , 0.0f , 1.0f};

    }
    if (rotation_vec.y == 1.0f)  //Drehung um Y-Achse
    {
        rotation_mat[0] =  glm::vec4 {cos(winkel) , 0.0f , -sin(winkel) , 0.0f};
        rotation_mat[1] =  glm::vec4 {0.0f , 1.0f , 0.0f , 0.0f};
        rotation_mat[2] =  glm::vec4 {sin(winkel) , 0.0f , cos(winkel) , 0.0f};
        rotation_mat[3] =  glm::vec4 {0.0f , 0.0f , 0.0f , 1.0f};
  
    }
    if (rotation_vec.z == 1.0f)  //Drehung um Z-Achse
    {
        rotation_mat[0] =  glm::vec4 {cos(winkel) , sin(winkel) , 0.0f , 0.0f};
        rotation_mat[1] =  glm::vec4 { - sin(winkel) , cos(winkel) , 0.0f , 0.0f};
        rotation_mat[2] =  glm::vec4 {0.0f , 0.0f , 1.0f , 0.0f};
        rotation_mat[3] =  glm::vec4 {0.0f , 0.0f , 0.0f , 1.0f};

    }

    return rotation_mat;
}






bool operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs)
{
    return lhs->name_ < rhs->name_ ;
};