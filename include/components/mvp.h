#ifndef SWAPIT_COMPONENTS_MVP_H_
#define SWAPIT_COMPONENTS_MVP_H_

#include <entityx/entityx.h>
#include "global.h"

struct MVP: public ex::Component<MVP> {
  MVP();
  MVP(double r, Color col);

  double r;
  Color col;
};

#endif  // SWAPIT_COMPONENTS_MVP_H_
