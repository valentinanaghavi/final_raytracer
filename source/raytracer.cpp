#include <renderer.hpp>
#include <window.hpp>
#include <scene.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>

int main(int argc, char* argv[])
{

  //unsigned const image_width = 1500;
  //unsigned const image_height = 1000;
  //unsigned const image_width = 480;
  //unsigned const image_height = 320;
  std::string const filename = "./checkerboard.ppm";

  Scene s;
  //std::string const ofile = "/home/valentina/final_raytracer/source/example.txt";
  std::string const ofile = "../../source/exampleLight.txt";
  
  s.read_sdf(ofile);

  unsigned const widthR = s.width_;
  unsigned const heightR = s.height_;
  std::string const fileTXT = s.filename_ ;
  std::cout << "renderer Bedingungen werden verarbeitet \n" << widthR << "\n" << heightR << "\n";
  
  Renderer renderer{s , widthR, heightR, fileTXT};
  //Renderer renderer{s ,image_width, image_height, filename};
  //create separate thread to see updates of pixels while rendering
  
  std::thread render_thread([&renderer]() {renderer.render();});
  std::cout << "fertig mit rendern \n" ;

  Window window{{widthR, heightR}};

  while (!window.should_close()) {
    if (window.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      window.close();
    }
    window.show(renderer.color_buffer());
  }

  //"join" threads, i.e. synchronize main thread with render_thread
  render_thread.join();
  return 0;
}
