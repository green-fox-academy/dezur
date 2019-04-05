#include <iostream>

int main(int argc, char* args[]) {

  // Write a program that stores a number, and the user has to figure it out.
  // The user can input guesses, after each guess the program would tell one
  // of the following:
  //
  // The stored number is higher
  // The stried number is lower
  // You found the number: 8

  int storedNumber, enteredNumber;

  storedNumber = 8;

  while (storedNumber != enteredNumber) {
    std::cout << "Enter number\n";
    std::cin >> enteredNumber;
    if (enteredNumber == storedNumber) {
      std::cout << "You found the number: " << storedNumber;
      return 0;
    } else if (enteredNumber < storedNumber) {
      std::cout << "The stored number is higher\n";
    } else {
      std::cout << "The stored number is lower\n";
    }
  }

  return 0;
}