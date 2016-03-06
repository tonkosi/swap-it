#ifndef SWAPIT_EVENTS_INPUT_EVENTS_H_
#define SWAPIT_EVENTS_INPUT_EVENTS_H_

#include <entityx/entityx.h>

#include "global.h"

// Kad pritisnete mouse button
struct MouseDownEvent : public ex::Event<MouseDownEvent> {
  MouseDownEvent(unsigned int x, unsigned int y)
      : x(x), y(y) {
  }

  unsigned int x, y;
};

// Kad podignete mouse button (release)
struct MouseUpEvent : public ex::Event<MouseUpEvent> {
  MouseUpEvent(unsigned int x, unsigned int y)
      : x(x), y(y) {
  }

  unsigned int x, y;
};

// Kad scrollas misem
struct MouseScrollEvent : public ex::Event<MouseScrollEvent> {
  MouseScrollEvent(int delta)
      : delta(delta) {
  }
  
  int delta;
};

// Kad god pomaknete mis
struct MouseMoveEvent : public ex::Event<MouseMoveEvent> {
  MouseMoveEvent(unsigned int x, unsigned int y)
      : x(x), y(y) {
  }
  
  unsigned int x, y;
};

// Trenutak kad pritisnete tipku
struct KeyDownEvent : public ex::Event<KeyDownEvent> {
  KeyDownEvent(const sf::Keyboard::Key& key)
      : key(key) {
  }

  sf::Keyboard::Key key;
};

// Trenutak kad podignete tipku
struct KeyUpEvent : public ex::Event<KeyUpEvent> {
  KeyUpEvent(const sf::Keyboard::Key& key)
      : key(key) {
  }

  sf::Keyboard::Key key;
};

// kad unesete neki sadrzaj
struct TextEnterEvent : public ex::Event<TextEnterEvent> {
  TextEnterEvent(const sf::Keyboard::Key& key)
      : keycode(keycode) {
  }

  unsigned int keycode;
};

#endif  // SWAPIT_EVENTS_INPUT_EVENTS_H_
