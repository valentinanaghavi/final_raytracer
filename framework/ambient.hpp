#ifndef BUW_AMBIENT_HPP
#define BUW_AMBIENT_HPP

#include <iostream>

#include "color.hpp"

struct Ambient
{
  Ambient () :
  color_(0.0f , 0.0f , 0.0f)
  {};

  Ambient(Color color) : 
  color_(color)
  {};

  friend std::ostream& operator<<(std::ostream& os, Ambient const& a)
  {
    os << "AMBIENT: color: (" << a.color_.r  << a.color_.g << ","  << a.color_.b <<  ")\n";
    return os;
  }

  Color color_ ;

};

#endif //#define BUW_AMBIENT_HPP