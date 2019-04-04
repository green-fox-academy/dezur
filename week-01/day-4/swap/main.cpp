#include <iostream>
#include <string>

void swap(int& a, int& b);

int main(int argc, char* args[]) {
  // Create two integer variables: a=15, b=23
  // Create a function named swap that gets the 2 integers as parameters and swaps its values.
  // Print the values before and after the function call and make sure the values are printed in reversed order.
  int a = 15;
  int b = 23;

  std::cout << "Original values: " << a << " | " << b << std::endl;
  swap(a, b);
  std::cout << "swapped values: " << a << " | " << b << std::endl;
  return 0;
}

void swap(int& a, int& b) {
  int c;
  c = a;
  a = b;
  b = c;
}