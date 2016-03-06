#include "utils/random.h"

// vraca realnu vrijednost izmedju [0 .. 1]
double rand01() {
  return rand() / (double)RAND_MAX;
}

double randomDouble() {
  return (double)rand() + rand01();
}

double randomDouble(double lo, double hi) {
  return lo + randomDouble() / RAND_MAX * (hi - lo);
}

