#ifndef SWAPIT_SYSTEMS_RENDER_SYSTEM_H_
#define SWAPIT_SYSTEMS_RENDER_SYSTEM_H_

#include <entityx/entityx.h>

#include "global.h"

#include "components/position.h"
#include "components/velocity.h"
#include "components/mvp.h"

class RenderSystem : public ex::System<RenderSystem> {
 public: 
  RenderSystem();
  
  void update(ex::EntityManager &entites, ex::EventManager &events, double dt);

 private:
  // .. bla bla bla
};

#endif  // SWAPIT_SYSTEMS_RENDER_SYSTEM_H_
