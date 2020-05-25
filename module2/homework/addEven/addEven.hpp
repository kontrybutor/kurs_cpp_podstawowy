#pragma once
#include <vector>

int addEven(const std::vector<int> &numbers) {
  int evenSum{};

  for (const auto &number : numbers) {
    if (0 == number % 2) {
      evenSum += number;
    }
  }
  return evenSum;
}
