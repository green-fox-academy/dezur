
#include <iostream>

int main(int argc, char *args[]) {

  // Write a program that asks for a number.
  // It would ask this many times to enter an integer,
  // if all the integers are entered, it should print the sum and average of these
  // integers like:
  //
  // Sum: 22, Average: 4.4

  float number, sum;

  for (int i = 0; i < 5; ++i) {
    std::cout << "Enter " << i+1 << ". number:\n";
    std::cin >> number;
    sum += number;
  }

  std::cout << "Sum: " << sum << ", Average: " << sum/5;

  return 0;
}