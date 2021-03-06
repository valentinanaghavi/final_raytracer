// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

Renderer::Renderer(Scene const& scene , unsigned w, unsigned h, std::string const& file)
  : scene_(scene)
  , width_(w)
  , height_(h)
  , color_buffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}


//erste Versuch
/*void Renderer::render()
{
  std::size_t const checker_pattern_size = 20;
  Ray ray;
  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      Material mat;
      Sphere sphere (glm::vec3{0,-80,110},100,"kugel",mat);
      ray.direction = {glm::vec3{(float)x-height_/2,(float)y-width_/2,100}};
      float a = 10.0f;
      
      if(sphere.intersect(ray,a))
      {
          if ( ((x/checker_pattern_size)%2) != ((y/checker_pattern_size)%2)) 
          {
              p.color = Color(0.0, 1.0, float(x)/height_);
          } 
          else 
          {
              p.color = Color(1.0, 0.0, float(y)/width_);
          }
      }
       write(p);
    }
  }
  ppm_.save(filename_);
}*/
void Renderer::render()
{
 // std::size_t const checker_pattern_size = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      Ray ray = scene_.camera_.camera_ray(x,y,width_,height_);
      p.color = raytrace(ray,40); //depth wird festgelegt für die Tiefe/Anzahl der Spiegelungen
      p.color = toneMapping(p.color);
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

/*
!!tone mapping soll in der Ausgabedatei bzw im Window angezeigt werden !!

Tone Mapping ist die Verrringerung des Kontrastes eines Hochkontrastbildes fuer ein naturgetreu wirkende Darstellung.
Berechnung des finalen Farbwertes.
Dabei ist c (hdr) ist der berechnete Farbwert vom raytracer.
*/
Color Renderer :: toneMapping (Color const& c) const
{
  Color c_ldr ;
  c_ldr.r = c.r / (c.r+1);
  c_ldr.g = c.g / (c.g+1);
  c_ldr.b = c.b / (c.b+1);

  return c_ldr ;

}

Color Renderer::raytrace(Ray const& ray, unsigned int depth) const
{
  Strike closest = scene_.composite_ -> intersection(ray); ///ohne composite : computeStrike

  Color ia = scene_.ambient_;
  

  if(closest.hit == true)
  {
    /* Ambiente Beleuchtung = I_a*k_a   I_a: Intensitaet des ambienten Lichts, bestimmt
    durch konstante I_a = 0.10 (keine Konstante mehr, festgelegt durch ambientes Licht)
    k_a: ambienter Reflexionskoeffizient (in Material ka = ambiente Reflexion*/
    Color c {0.0, 0.0, 0.0};
    Color ip {0.0, 0.0, 0.0};
    float ln = 0;
    float rv = 0;
    c = ia * (closest.nearestShape -> getMaterial().ka_); //ia (ambient light) * ambient reflektion der Shape 

    //Falls andere Lichtquellen vorhanden werden diese durchgegangen
    for (unsigned int i = 0; i < scene_.light_vector.size(); i++)
    {
      if (breaking(closest, scene_.light_vector[i] -> pos_)) // wenn es keinen Schatten gibt 
      {
        ip = scene_.light_vector[i] -> intensity(); // Intensitaet: brightness * color
        
        glm::vec3 l = glm::normalize(scene_.light_vector[i]->pos_ - closest.origin); //Vektor zur Lichtquelle
        glm::vec3 n = glm::normalize(closest.normal); //Normalenvektor von Strike
        // ln: i_p * k_d || i_p: Helligkeit Puntlichtquelle, k_d: diffuser Reflexionskoeffizient
        ln = std::max(0.0f, glm::dot(l,n)); //dot: Skalarprodukt der beiden normalisierten Vektoren l und n float als Ergebnis
        
        // in der Folie S.14 l+r = 2(n*l)n, also r = (2*(ln)*n-l)
        glm::vec3 r = glm::normalize(2 * ln * n - l);
        glm::vec3 v = - ray.direction; // v: Vektor zum Betrachter. Ray geht vom Betrachter aus -> ZUM also -
        //rv: cos^m ß -> (r*v)^m || r: reflektierter Lichtvektor, v: Vektor zum Betrachter
        rv = std::max(0.0f, glm::dot(r,v));

    

        // Ip * (kd * (ln) + ks * (rv)^m)
        c += ip * (ln * (closest.nearestShape -> getMaterial().kd_) 
            + (closest.nearestShape -> getMaterial().ks_) 
            * std::pow(rv, (closest.nearestShape -> getMaterial().m_)));
        
      }
    
    }

    //Reflektion anderer Objekte
    //if depth > 0 || ist es größer null gibt es eine Tiefe es koennen also auch andere Objekte vorhanden sein die spiegeln
    if (depth > 0)
    {
      //reflect:: reflektiert Vektor V1 mit der Orientierung von Vektor V2, wird an der Normalen gespiegelt
      //mit der Formel V1 - 2.0 * dot(V2,V1) * V2
      glm::vec3 mirrorDirection = glm::normalize(glm::reflect(ray.direction, closest.normal));
      //Mirror-Ray berechnen aus Ursprung + leichte Verschiebung und der Mirrordirection
      Ray mirrorRay {(closest.origin + (0.0001f * mirrorDirection)), mirrorDirection};
      // mirrorRay raytracen mit verringerter Tiefe
      Color reflection = raytrace(mirrorRay, depth -1);


      /*Die Farbe der Spiegelung berechnet sich zur Hälfte aus der color c und 
      zur Haelfte aus aus der Color c * gespiegelte Farbe * ks (specular reflection)
      * m (specular reflection exponent)*/
      float m = closest.nearestShape -> getMaterial().m_; //ich glaube anstatt m soll refract irgendwas dahin !
      //float refract = closest.nearestShape -> getMaterial().refract_;       
      Color ks = closest.nearestShape -> getMaterial().ks_;
      c = c * 0.5f + c * 0.5f * reflection * ks * m;
     
     /*
      //Refraction , oben noch refractionparamter hinzufuegen
      float o =  closest.nearestShape -> getMaterial().opacity_ ;

      glm::vec3 transparentDirection = glm::normalize(glm::refract(ray.direction, closest.normal, o));
      Ray transparentRay {(closest.origin + (0.0001f * transparentDirection)), transparentDirection};
      Color refraction = raytrace(transparentRay, depth -1);

      c += refraction * ks * (1 - refract) ;//anstelle von m refract parameter und noch in material einfuegen  */
      return c;  
    }

  }
  else
  {
    Color c = ia;
    return c;
  }

    
}
/* Die Funktion schaut ob ein Objekt zwischen dem Strike eines Objetes und einer der / allen 
Lichtquellen liegt. Liegt ein Objekt dazwischen gibt es einen Schatten*/ 
bool Renderer::breaking (Strike const& strike, glm::vec3 const& lightPosition) const
{
  float a = 0.001f; 

  glm::vec3 point = strike.origin + (a * glm::normalize(strike.normal)); 
  // ohne composite:
  //Strike shadow = computeStrike(Ray{point, lightPosition - point}); 
  Strike shadow = scene_.composite_ -> intersection(Ray{point, lightPosition - point});
    
  return (!shadow.hit || glm::length(point - lightPosition) < glm::length(point - shadow.origin));
}

Strike Renderer::computeStrike(Ray const& rayStrike) const
{
  Strike closest;
  //float d = 2000;

  for (auto const& shape: scene_.shape_vector)
  {
    if(shape != nullptr)
    {
      Ray ray{rayStrike.origin, glm::normalize(rayStrike.direction)};

      Strike newStrike = shape -> intersection(ray);

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
