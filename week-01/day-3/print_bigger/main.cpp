#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int firstNumber;
    int secondNumber;

    std::cout << "Enter first number:";
    std::cin >> firstNumber;
    std::cout << "Enter second number:";
    std::cin >> secondNumber;

    if (firstNumber > secondNumber) {
        std::cout << firstNumber;
    } else
        std::cout << secondNumber;

    return 0;
}