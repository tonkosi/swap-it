#ifndef SWAPIT_SYSTEMS_SPAWN_SYSTEM_H_
#define SWAPIT_SYSTEMS_SPAWN_SYSTEM_H_

#include <queue>
#include <tuple>

#include <entityx/entityx.h>

#include "events/events.h"
#include "global.h"
#include "components/position.h"
#include "components/velocity.h"
#include "components/mvp.h"

class SpawnSystem : public ex::System<SpawnSystem>,
                    public ex::Receiver<SpawnSystem> {
 public: 
  SpawnSystem();
  
  void configure(ex::EventManager& events);

  void update(ex::EntityManager &entites, ex::EventManager &events, double dt);

  void receive(const MouseDownEvent& ev);
  void receive(const MouseScrollEvent& ev);

 private:
  std::queue<std::tuple<double, double, double, double, double>> queue_;
};

#endif  // SWAPIT_SYSTEMS_SPAWN_SYSTEM_H_
