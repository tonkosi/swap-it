#ifndef SWAPIT_CORE_WINDOW_MANAGER_H_
#define SWAPIT_CORE_WINDOW_MANAGER_H_

#include <SFML/Graphics.hpp>

#include "global.h"

class WindowManager {
 public:
  static constexpr unsigned int WIN_WIDTH  = 960;
  static constexpr unsigned int WIN_HEIGHT = 540;

  static void Create();
  
  static bool IsOpen();

  static void Loop();

  static void Close();
  
  static bool PollEvent(sf::Event& event);
  
  static void Clear();

  static void Draw(const sf::Drawable& drawable,
                   const sf::RenderStates& states = sf::BlendAlpha,
                   sf::Shader *shader = nullptr);
  
  static void Display();
 
 private:
  static sf::RenderWindow render_window_;
};

#endif  // SWAPIT_CORE_WINDOW_MANAGER_H_
