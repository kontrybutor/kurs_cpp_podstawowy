#pragma once
#include <functional>
#include <map>
#include <string>

std::string calculate(const std::string &command, int first, int second) {
  auto calculator =
      std::map<std::string, std::function<std::string(int, int)>>{};

  calculator.try_emplace("add", [&](const auto first, const auto second) {
    return std::to_string(first + second);
  });
  calculator.try_emplace("subtract", [&](const auto first, const auto second) {
    return std::to_string(first - second);
  });
  calculator.try_emplace("multiply", [&](const auto first, const auto second) {
    return std::to_string(first * second);
  });
  calculator.try_emplace("divide", [&](const auto first, const auto second) {
    return second != 0 ? std::to_string(first / second) : "Division by 0";
  });

  if (calculator.find(command) != calculator.end()) {
    return calculator[command](first, second);
  }

  return "Invalid data";
}