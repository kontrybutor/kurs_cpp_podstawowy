#pragma once
#include <numeric>
#include <vector>

template <typename InputIterator, typename AccumulateType,
          typename BinaryOperation, typename Predicate>
const AccumulateType
accumulate_if(InputIterator first, const InputIterator last,
              AccumulateType init, BinaryOperation &&binary_op,
              Predicate &&predicate) {
  for (; first != last; ++first) {
    if (predicate(*first)) {
      init = binary_op(init, *first);
    }
  }
  return init;
}

int addEven(const std::vector<int> &numbers) {

  return accumulate_if(numbers.begin(), numbers.end(), 0, std::plus<int>{},
                       [](const auto i) { return i % 2 == 0; });
}
