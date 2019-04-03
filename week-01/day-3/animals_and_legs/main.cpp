#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chickens;
    int pigs;
    int legs;

    std::cout << "Enter number of chickens:";
    std::cin >> chickens;
    std::cout << "Enter number of pigs:";
    std::cin >> pigs;
    std::cout << "All of the animals have " << chickens * 2 + pigs * 4 << " legs.";

    return 0;
}