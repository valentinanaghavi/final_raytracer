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
                       //Box box;
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
                       //Sphere sphere;
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
                    //scene.light_map.insert(std::pair<std::string,std::shared_ptr<Light>> (light_path->name_, light_path));
                    scene.light_vector.push_back(light_path);

                }
            
                else if (b == "ambient")
                {
                     Color color;

                    buffer >> a;
                    buffer >> color.r;
                    buffer >> color.g;
                    buffer >> color.b;

                    std::shared_ptr<Ambient> ambient_path = std::make_shared<Ambient>(color);
                    scene.ambient_vector.push_back(ambient_path);
                }
                else if (b == "camera")
                {
                    std::string name;
                    float fovX;
                    glm::vec3 eye;
                    glm::vec3 dir;
                    glm::vec3 up;

                    buffer >> a;
                    buffer >> name;
                    buffer >> fovX;
                    buffer >> eye.x;
                    buffer >> eye.y;
                    buffer >> eye.z;
                    buffer >> dir.x;
                    buffer >> dir.y;
                    buffer >> dir.z;
                    buffer >> up.x;
                    buffer >> up.y;
                    buffer >> up.z;

                    std::shared_ptr<Camera> camera_path = std::make_shared<Camera>(name , fovX, eye, dir, up);
                    scene.camera_vector.push_back(camera_path);
                }
            }
/***********************************DEFINE-END***************TRANSFORM-START***********************************************************/
            else if (a == "transform")
            {
                //fuer cam auch??
                std::string shape_name;

                buffer >> shape_name;

                //auto foundShape = findShape.find(shape_name);

                if(foundShape != findShape.end())
                {
                    buffer >> c ;

                    if(c == "scale")
                    {
                        glm::vec3 s;

                        buffer >> s.x;
                        buffer >> s.y;
                        buffer >> s.z;

                        glm::mat4 scale_mat = scale(s);
                        glm::mat4 trans_mat = shape -> getWorld_trans;
                        trans_mat *= translate_mat ;
                        shape -> setWorld_trans(trans_mat);
                        shape -> setWorld_trans_inv(glm::inverse(trans_mat));
                    
                    }
                    else if(c == "translate")
                    {
                        glm::vec3 t;

                        buffer >> t.x;
                        buffer >> t.y;
                        buffer >> t.z;

                        glm::mat4 translate_mat = translate(s);
                        glm::mat4 trans_mat = shape -> getWorld_trans;
                        trans_mat *= translate_mat ;
                        shape -> setWorld_trans(trans_mat);
                        shape -> setWorld_trans_inv(glm::inverse(trans_mat));

                    }
                    else if(c == "rotate")
                    {
                        float winkel;
                        glm::vec3 r;
                        
                        buffer >> winkel;
                        buffer >> r.x;
                        buffer >> r.y;
                        buffer >> r.z;
                        
                        glm::mat4 rotate_mat = rotate(winkel,r);
                        glm::mat4 trans_mat = shape -> getWorld_trans;
                        trans_mat *= rotate_mat ;
                        shape -> setWorld_trans(trans_mat);
                        shape -> setWorld_trans_inv(glm::inverse(trans_mat));
                    }
                    else
                    {
                        std::cout << "Transform Funktion kann nicht gelesen werden."<< std::endl;
                    }
                }               
            }
/***********************************TRANSFROM_END************RENDER-START**************************************************************/
            else if( a == "render")
            {
                buffer >> scene_.width;
                buffer >> scene_.height;
                buffer >> scene_.filename;

            }
        
        }
        myfile.close();
    

};

glm::mat4 SdfReader :: translation(glm::vec3 trans_vec)
{
    glm::mat4 trans_mat;

    trans_mat[0] = glm::vec4 {1.0f , 0.0f , 0.0f , 0.0f};
    trans_mat[1] = glm::vec4 {0.0f , 1.0f , 0.0f , 0.0f};
    trans_mat[2] = glm::vec4 {1.0f , 0.0f , 1.0f , 0.0f};
    trans_mat[3] = glm::vec4 {trans_vec , 1.0f};
    
    return trans_mat ;
}

glm::mat4 SdfReader :: inverse_translation(glm::vec3 trans_vec)
{
    glm::mat4 trans_mat;

    trans_mat[0] = glm::vec4 {1.0f , 0.0f , 0.0f , 0.0f};
    trans_mat[1] = glm::vec4 {0.0f , 1.0f , 0.0f , 0.0f};
    trans_mat[2] = glm::vec4 {1.0f , 0.0f , 1.0f , 0.0f};
    trans_mat[3] = glm::vec4 {trans_vec *(-1.0f) , 1.0f};
    
    return trans_mat ;    
}

glm::mat4 SdfReader :: scale(glm::vec3 scale_vec)
{
    glm::mat4 scale_mat;

    scale_mat[0] = glm::vec4 {scale_vec.x , 0.0f , 0.0f , 0.0f};
    scale_mat[1] = glm::vec4 {0.0f , scale_vec.y , 0.0f , 0.0f};
    scale_mat[2] = glm::vec4 {1.0f , 0.0f , scale_vec.z , 0.0f};
    scale_mat[3] = glm::vec4 {0.0f,  0.0f , 0.0f , 1.0f};
    
    return scale_mat ;   

} 

glm::mat4 SdfReader :: rotation(glm::vec3 rotation_vec, float winkel) //Winkel in Bogenmaß !!
{
    glm::mat4 rotation_mat;

    if (rotation_vec.x == 1.0f) //Drehung um X-Achse
    {
        rotation_mat[0] = {1.0f , 0.0f , 0.0f , 0.0f};
        rotation_mat[1] = {0.0f , cos(winkel) , sin(winkel) , 0.0f};
        rotation_mat[2] = {0.0f , - sin(winkel) , cos(winkel) , 0.0f};
        rotation_mat[3] = {0.0f , 0.0f , 0.0f , 1.0f};

    }
    if (rotation_vec.y == 1.0f)  //Drehung um Y-Achse
    {
        rotation_mat[0] = {cos(winkel) , 0.0f , -sin(winkel) , 0.0f};
        rotation_mat[1] = {0.0f , 1.0f , 0.0f , 0.0f};
        rotation_mat[2] = {sin(winkel) , 0.0f , cos(winkel) , 0.0f};
        rotation_mat[3] = {0.0f , 0.0f , 0.0f , 1.0f};
  
    }
    if (rotation_vec.z == 1.0f)  //Drehung um Z-Achse
    {
        rotation_mat[0] = {cos(winkel) , sin(winkel) , 0.0f , 0.0f};
        rotation_mat[1] = { - sin(winkel) , cos(winkel) , 0.0f , 0.0f};
        rotation_mat[2] = {0.0f , 0.0f , 1.0f , 0.0f};
        rotation_mat[3] = {0.0f , 0.0f , 0.0f , 1.0f};

    }

    return rotation_mat;
}


bool operator<(std::shared_ptr<Material> const& lhs , std::shared_ptr<Material> const& rhs)
{
    return lhs->name_ < rhs->name_ ;
};

