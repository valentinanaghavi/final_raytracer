#include <renderer.hpp>
#include <window.hpp>
#include <sdfReader.hpp>
#include <scene.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>

int main(int argc, char* argv[])
{
  unsigned const image_width = 800;
  unsigned const image_height = 600;
  //unsigned const image_width = 1600;
  //unsigned const image_height = 900;
  std::string const filename = "./checkerboard.ppm";
  Scene s = read_sdf("/home/final_raytracer/source/example.sdf");
  Renderer renderer{s ,image_width, image_height, filename};
  std::cout << "renderer generiert:" ;
  //create separate thread to see updates of pixels while rendering
  std::thread render_thread([&renderer]() {renderer.render();});

  Window window{{image_width, image_height}};

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
