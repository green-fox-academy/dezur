#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    int number;
    double sumOfNumbers;
    double averageOfNumbers;

    for (int i=0; i < 5; i++){
        std::cout << "Enter " << i+1 << ". number:";
        std::cin >> number;
        sumOfNumbers = sumOfNumbers + number;
    }
    averageOfNumbers = sumOfNumbers / 5;
    std::cout << "Sum: " << sumOfNumbers << ", Average: " << averageOfNumbers;

    return 0;
}