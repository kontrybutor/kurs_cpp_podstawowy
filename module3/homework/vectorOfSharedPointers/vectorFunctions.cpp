#include "vectorFunctions.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
  std::vector<std::shared_ptr<int>> vec;
  vec.reserve(count);
  for (size_t i = 0; i < count; ++i) {
    vec.emplace_back(std::make_shared<int>(i));
  }
  return vec;
}

void print(const std::vector<std::shared_ptr<int>> &vec) {
  for (const auto &elem : vec) {
    std::cout << *elem << '\n';
  }
}
void add10(std::vector<std::shared_ptr<int>> &vec) {
  for (const auto &elem : vec) {
    if (elem) {
      *elem += 10;
    }
  }
}
void sub10(std::vector<std::shared_ptr<int>> &vec) {
  for (const auto &elem : vec) {
    sub10(elem.get());
  }
}
void sub10(int *const elem) {
  if (elem) {
    *elem -= 10;
  }
}
