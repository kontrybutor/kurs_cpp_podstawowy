#pragma once
#include <vector>

int maxOfVector(const std::vector<int> &vec) {

  int maxNumber = vec[0];
  for (const auto &number : vec) {
    maxNumber = number > maxNumber ? number : maxNumber;
  }
  return maxNumber;
}
