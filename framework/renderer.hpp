// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include "scene.hpp"
#include "Ray.hpp"
#include "strike.hpp"
#include "sphere.hpp"
#include <string>
#include <glm/glm.hpp>


class Renderer
{
public:
  Renderer(unsigned w, unsigned h, std::string const& file);

  void render();
  void write(Pixel const& p);
  Color raytrace(Ray const& ray, unsigned int depth) const;
  Strike computeStrike(Ray const& ray) const;
  bool breaking (Strike const& strike, glm::vec3 const& lightPosition) const;

  inline std::vector<Color> const& color_buffer() const
  {
    return color_buffer_;
  }

private:
  unsigned width_;
  unsigned height_;
  unsigned int depth;
  std::vector<Color> color_buffer_;
  std::string filename_;
  PpmWriter ppm_;
  Scene scene_;
};

#endif // #ifndef BUW_RENDERER_HPP
