#ifndef SWAPIT_UTILS_COLOR_H_
#define SWAPIT_UTILS_COLOR_H_

#include <SFML/Graphics.hpp>

struct Color {
  double r, g, b, a;

  Color();
  Color(double r, double g, double b);
  Color(double r, double g, double b, double a);
  Color(const sf::Color& color);

  static Color getRandom();
  static Color HSV_to_RGB(double h, double s, double v);
};

#endif  // SWAPIT_UTILS_COLOR_H_
