#include <cstdio>
#include <entityx/entityx.h>

#include "global.h"
#include "core/app.h"

int main(void) {
  srand(time(NULL));
  
  App app;
  app.init();
  app.run();

  return 0;
}
