#include <iostream>

int main(int argc, char *args[]) {

  // Write a program that reads a number from the standard input, then draws a
  // pyramid like this:
  //
  //
  //    *
  //   ***
  //  *****
  // *******
  //
  // The pyramid should have as many lines as the number was

  int number, i, j, space;

  std::cout << "Enter number\n";
  std::cin >> number;

  for (i = 1; i <= number; i++) {
    for (space = i; space < number; space++) {
      std::cout << " ";
    }
    for (j = 1; j <= (2 * i - 1); j++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }

  return 0;
}