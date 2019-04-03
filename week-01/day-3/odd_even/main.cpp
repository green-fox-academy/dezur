#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    int number;

    std::cout << "Enter a number:";
    std::cin >> number;
    if (number % 2 == 0) {
        std::cout << "Odd";
    } else {
        std::cout << "Even";
    }

    return 0;
}