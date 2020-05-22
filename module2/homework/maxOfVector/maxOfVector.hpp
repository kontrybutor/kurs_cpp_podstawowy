#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    // TODO: Implement me :)
    int maxNumber = vec[0];
    for(const auto& number: vec){
        maxNumber = number > maxNumber ? number : maxNumber;
    }

    return maxNumber;
}
