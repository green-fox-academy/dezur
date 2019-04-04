#include <iostream>
#include <string>

int main(int argc, char *args[]) {

  // - Create an array variable named `s`
  //   with the following content: `[1, 2, 3, 8, 5, 6]`
  // - Change the 8 to 4
  // - Print the fourth element

  int s[6] = {1, 2, 3, 8, 5, 6};

  s[3] = 4;

  std::cout << s[3];

  return 0;
}