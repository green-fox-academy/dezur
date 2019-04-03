#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    double kilometers;
    double miles;

    std::cout << "Enter distance in kilometer: ";
    std::cin >> kilometers;
    miles = kilometers * 0.62;
    std::cout << kilometers << " kilometers is " << miles << " miles.";

    return 0;
}