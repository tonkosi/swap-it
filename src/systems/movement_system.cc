#include "systems/movement_system.h"

MovementSystem::MovementSystem() {
}

void MovementSystem::update(ex::EntityManager &entities,
                            ex::EventManager &events, double dt) {
  entities.each<Position, Velocity>([dt](
      ex::Entity, Position &pos, Velocity &vel) {
    pos.x += vel.x * dt;
    pos.y += vel.y * dt;
  });
}
