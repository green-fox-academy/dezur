#include <iostream>
#include <string>

int sum(int a);

int main(int argc, char* args[]) {

  // Write a function called `sum` that returns the sum of numbers from zero to the given parameter
  int number;
  std::cout << "Enter number\n";
  std::cin >> number;
  std::cout << sum(number);

  return 0;
}

int sum(int a){
  int b = 0;
  for(int i = 0; i <= a; i++) {
    b += i;
  }
  return b;
}