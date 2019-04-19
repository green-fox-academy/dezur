#include <iostream>

#include "dice_set.h"

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    int sum = 0;
    int counter = 1;
    DiceSet diceSet;

    while(sum != 36) {
        sum = 0;
        diceSet.roll();
        //std::cout << counter << " : ";
        for (int i = 0; i < 6; ++i) {
            sum += diceSet.getCurrent(i);
            //std::cout << diceSet.getCurrent(i) << " ";
        }
        //std::cout << std::endl;
        counter++;
    }
    std::cout << "Finished: " << counter-1 << ". roll";

    return 0;
}