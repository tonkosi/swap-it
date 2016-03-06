#ifndef SWAPIT_COMPONENTS_VELOCITY_H_
#define SWAPIT_COMPONENTS_VELOCITY_H_

#include <entityx/entityx.h>

#include "global.h"

struct Velocity: public ex::Component<Velocity> {
  Velocity();
  Velocity(double x, double y);

  double x, y;
};

#endif  // SWAPIT_COMPONENTS_VELOCITY_H_
