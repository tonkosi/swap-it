#include "systems/spawn_system.h"
#include "events/events.h"

#include "components/position.h"
#include "components/velocity.h"

SpawnSystem::SpawnSystem() {
}

void SpawnSystem::configure(ex::EventManager& events) {
  events.subscribe<MouseDownEvent>(*this);
}

void SpawnSystem::update(ex::EntityManager &entities,
                         ex::EventManager &events, double dt) {
  static int cnt = 0;
  while (!queue_.empty()) {
    printf("cnt = %d, dt = %.3lf\n", ++cnt, dt);
    double x, y, dx, dy, r;
    std::tie(x, y, r, dx, dy) = queue_.front();
    queue_.pop();

    ex::Entity ent = entities.create();
    ent.assign<Position>(x, y);
    ent.assign<Velocity>(dx, dy);
    ent.assign<MVP>(r, Color::GetRandom());
  }
}

void SpawnSystem::receive(const MouseDownEvent& ev) {
  int radius = 8 + rand() % 20;
  int dx = rand() % 70 - 35;
  int dy = rand() % 70 - 35;
  queue_.push(std::make_tuple(ev.x, ev.y, radius, dx, dy));
}
