#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

int fibonacci_iterative(int sequence) {

  if (sequence == 0) {
    return 0;
  }
  std::vector<int> v(sequence, 1);
  std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1,
                           std::plus<int>{});
  return v[sequence - 1];
}

int fibonacci_recursive(int sequence) {
  if (sequence <= 1) {
    return sequence;
  }
  return fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1);
}
