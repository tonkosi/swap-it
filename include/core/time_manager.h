#ifndef SWAPIT_CORE_TIME_MANAGER_H_
#define SWAPIT_CORE_TIME_MANAGER_H_

#include <SFML/System.hpp>

class TimeManager {
 public:
  static sf::Time GetDelta();
  static void Restart();
 
 private:
  static sf::Clock clock_;
  static sf::Time delta_;
}

#endif  // SWAPIT_CORE_TIME_MANAGER_H_
