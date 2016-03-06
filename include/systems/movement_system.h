#ifndef SWAPIT_SYSTEMS_MOVEMENT_SYSTEM_H_
#define SWAPIT_SYSTEMS_MOVEMENT_SYSTEM_H_

#include <entityx/entityx.h>

#include "global.h"

#include "components/position.h"
#include "components/velocity.h"

class MovementSystem : public ex::System<MovementSystem> {
 public: 
  MovementSystem();
  
  void update(ex::EntityManager &entites, ex::EventManager &events, double dt);

 private:
};

#endif  // SWAPIT_SYSTEMS_MOVEMENT_SYSTEM_H_
