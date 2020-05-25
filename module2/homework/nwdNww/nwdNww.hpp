#pragma once
#include <cmath>

int NWD(int lhs, int rhs) {

  if (lhs == 0) {
    return abs(rhs);
  } else if (rhs == 0) {
    return abs(lhs);
  }
  return NWD(rhs, lhs % rhs);
}

int NWW(int lhs, int rhs) {
  return (lhs != 0 && rhs != 0) ? (abs(lhs) / NWD(lhs, rhs)) * abs(rhs) : 0;
}