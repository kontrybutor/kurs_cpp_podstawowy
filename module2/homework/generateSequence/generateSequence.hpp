#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {

  std::vector<int> vec{};
  for (auto i = 0, s = step; i < count; i++, s += step) {
    vec.push_back(s);
  }
  return vec;
}
