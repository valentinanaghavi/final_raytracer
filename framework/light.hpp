#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP

#include <iostream>
#include <string>
#include <glm/vec3.hpp>

#include "color.hpp"


struct Light
{
  Light () :
  name_("no Name"), 
  pos_(0.0f , 0.0f , 0.0f), 
  color_(0.0f , 0.0f , 0.0f),
  brightness_(0.0f) 
  {};
  //INTENSITAET DER LICHTQUELLE = BRIGHTNESS*COLOR
  Light(std::string name, glm::vec3 pos, Color color , float brightness) : 
  name_(name), 
  pos_(pos), 
  color_(color),
  brightness_(brightness) 
  {};

  ~Light(){}

  Color intensity() const 
  {
    Color intensity {color_ * brightness_};
    return intensity;
  }

  friend std::ostream& operator<<(std::ostream& os, Light const& l)
  {
    os << "LIGHT: (name:" << l.name_ << ", position: (" << l.pos_.x << ","<< l.pos_.y << "," << l.pos_.z << ") , color: (" << l.color_.r  << l.color_.g << ","  << l.color_.b << ", brightness:" << l.brightness_ << ")\n";
    return os;
  }

  std::string name_; 
  glm::vec3 pos_; 
  Color color_; 
  float brightness_;
};

#endif //#define BUW_LIGHT_HPP