//
// Created by Zoli on 2019. 04. 25..
//

#include <algorithm>
#include "checkanagram.h"

bool checkAnagram(std::string word1, std::string word2)
{
    std::string sortedWord1 = word1;
    std::string sortedWord2 = word2;

    std::sort(sortedWord1.begin(), sortedWord1.end());
    std::sort(sortedWord2.begin(), sortedWord2.end());
    if (sortedWord1 == sortedWord2) {
        return true;
    } else {
        return false;
    }
}
