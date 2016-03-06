#ifndef SWAPIT_COMPONENTS_POSITION_H_
#define SWAPIT_COMPONENTS_POSITION_H_

#include <entityx/entityx.h>

#include "global.h"

struct Position: public ex::Component<Position> {
  Position();
  Position(double x, double y);

  double x, y;
};

#endif  // SWAPIT_COMPONENTS_POSITION_H_
