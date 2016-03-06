#include "utils/random.h"

// vraca realnu vrijednost izmedju [0 .. 1]
double Rand01() {
  return rand() / (double)RAND_MAX;
}

double RandomDouble() {
  return (double)rand() + Rand01();
}

double RandomDouble(double lo, double hi) {
  return lo + RandomDouble() / RAND_MAX * (hi - lo);
}

