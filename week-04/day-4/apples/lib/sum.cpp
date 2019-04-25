//
// Created by Zoli on 2019. 04. 25..
//

#include "sum.h"

int sum(std::vector<int> numbers)
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }
    return sum;
}
