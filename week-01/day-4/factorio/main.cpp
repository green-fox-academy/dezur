#include <iostream>
#include <string>

void factorio(int, long&);

int main(int argc, char *args[]) {

  // - Create a function called `factorio`
  //   it should calculate its input's factorial.
  //   it should not return it, but take an additional integer parameter and overwrite its value.

  int number;
  long result;

  std::cout << "Enter number\n";
  std::cin >> number;
  factorio(number, result);
  std::cout << result;
  return 0;
}

void factorio(int a, long& b) {
  b = 1;
  for(int i = 1; i <=a; ++i)
  {
    b *= i;
  }
}