#include "utils/color.h"

#include "utils/random.h"

Color::Color() : r(0.0), g(0.0), b(0.0), a(0.0) {
}

Color::Color(double r, double g, double b)
    : r(r), g(g), b(b), a(0.0) {
}

Color::Color(double r, double g, double b, double a)
    : r(r), g(g), b(b), a(a) {
}

Color::Color(const sf::Color& color) {
  r = color.r / 255.0;
  g = color.g / 255.0;
  b = color.b / 255.0;
  a = color.a / 255.0;
}

Color Color::getRandom() {
  double h = randomDouble(0, 360);
  double s = randomDouble(0.4, 0.6);
  double v = randomDouble(0.75, 1.0);
  return HSV_to_RGB(h, s, v);
}

Color Color::HSV_to_RGB(double h, double s, double v) {
  double c = v * s;
  double x = h / 60;
  while (x >= 2) x -= 2;
  x = c * (1 - fabs(x - 1));
  double m = v - c;
  double r = m, g = m, b = m;
  if (h < 60) r += c, g += x;
  else if (h < 120) r += x, g += c;
  else if (h < 180) g += c, b += x;
  else if (h < 240) g += x, b += c;
  else if (h < 300) r += x, b += c;
  else r += c, b += x;
  return Color(r, g, b);
}
