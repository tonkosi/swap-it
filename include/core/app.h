#ifndef SWAPIT_CORE_APP_H_
#define SWAPIT_CORE_APP_H_

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "core/window_manager.h"
#include "global.h"
#include "systems/movement_system.h"
#include "systems/spawn_system.h"
#include "systems/render_system.h"

#include "events/events.h"

class App : public ex::EntityX {
 public:
  App();
  ~App();

  void init();

  void run();

  void update(double dt);

  void draw(double dt);

 private:
};

#endif  // SWAPIT_CORE_APP_H_
