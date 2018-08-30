// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , color_buffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render()
{
  std::size_t const checker_pattern_size = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      if ( ((x/checker_pattern_size)%2) != ((y/checker_pattern_size)%2)) {
        p.color = Color(0.0, 1.0, float(x)/height_);
      } else {
        p.color = Color(1.0, 0.0, float(y)/width_);
      }

      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= color_buffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    color_buffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}

Color Renderer::raytrace(Ray const& ray, unsigned int depth) const
{
  Color c (0.0, 0.0, 0.0);
  Strike closest = computeStrike(ray);

  Color ambient {0.0, 0.0, 0.0};

  if(closest.hit == true) // -> in shape unterklassen muss Strike intersect geändert werden damit Strike.hit true wird
  {
    /* Ambiente Beleuchtung = I_a*k_a   I_a: Intensität des ambienten Lichts, bestimmt
    durch konstante I_a = 0.10     k_a: ambienter Reflexionskoeffizient (in Material
    ka = ambiente Reflexion*/
    float ia = 0.10;
    ambient = ia * (closest.nearestShape -> getMaterial() -> ka); //closest braucht pointer im Strike ist es ein nullptr muss im Strike intersect in den Shapes geändert werden dass es einen pointer bekommt beim methodenausführen 
 
    //Falls andere Lichtquellen vorhanden werden diese durchgegangen
    for (unsigned int i = 0; i < scene_.light_map.size(); i++)
    {
      if (breaking(closest, scene_.light_map[i] -> position)) // light muss glaub ich n vektor sein
      {
        

      }


    }


    
  }




}
/* Die Funktion schaut ob ein Objekt zwischen dem Strike eines Objetes und einer der / allen 
Lichtquellen liegt. Liegt ein Objekt dazwischen gibt es einen Schatten*/ 
bool Renderer::breaking (Strike const& strike, glm::vec3 const& lightPosition) const
{
  float a = 0.001f; //wieso 0.001?

  glm::vec3 point = strike.origin + (a * glm::normalize(strike.normal));

  Strike shadow = computeStrike(Ray{point, lightPosition - point}); //Wieso light position - Strikepunkt??
  
  return (!shadow.hit || glm::length(point - lightPosition) < glm::length(point - shadow.origin));
}

Strike Renderer::computeStrike(Ray const& rayStrike) const
{
  Strike closest;
  float d = 2000;

  for (auto const& shape: scene_.shape_vector)
  {
    if(shape != nullptr)
    {
      Ray ray{rayStrike.origin, glm::normalize(rayStrike.direction)};

      Strike newStrike = shape -> intersection(ray, d);

      if (newStrike.hit && 0.000001 < newStrike.distance && newStrike.distance < closest.distance) 
      {
        closest = newStrike;
      }
    }
    else
    {
      std::cout<< "shape == nullptr"<< std::endl;
    }
    return closest;
  }
}