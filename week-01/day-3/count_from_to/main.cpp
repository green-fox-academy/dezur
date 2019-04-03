#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5

    int firstNumber;
    int secondNumber;

    std::cout << "Enter first number:";
    std::cin >> firstNumber;
    std::cout << "Enter second number:";
    std::cin >> secondNumber;

    if (firstNumber < secondNumber) {
        for (int i=firstNumber; i<=secondNumber; i++) {
            std::cout << i << std::endl;
        }
    } else {
        std::cout << "The second number must be bigger!";
    }

    return 0;
}