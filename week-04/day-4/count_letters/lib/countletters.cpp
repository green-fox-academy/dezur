//
// Created by Zoli on 2019. 04. 25..
//

#include <algorithm>
#include "countletters.h"

std::map<char, int> countLetters(std::string line)
{
    std::map<char, int> count;
    std::map<char, int>::iterator mapIterator;

    for (int i = 0; i < line.size(); i++) {
        count[line[i]]++;
    }
    return count;
}
