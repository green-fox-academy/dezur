#include <iostream>
#include <vector>

#include "domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char *args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    std::cout << dominoes[0].toString();
    int domino = 0;

    for (int i = domino; i < dominoes.size(); ++i) {
        for (int j = 1; j < dominoes.size(); ++j) {
            if (dominoes[domino].getValues().second == dominoes[j].getValues().first) {
                domino = j;
                std::cout << dominoes[j].toString();
            }

        }

    }

    return 0;
}