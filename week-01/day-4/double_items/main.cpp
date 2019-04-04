#include <iostream>
#include <string>

int main(int argc, char *args[]) {

  // - Create an array variable named `numList`
  //   with the following content: `[3, 4, 5, 6, 7]`
  // - Double all the values in the array

  int numList[5] = {3, 4, 5, 6, 7};

  for (int i = 0; i < 5 ; ++i) {
    numList[i] = numList[i] * 2;
  }

  for (int j = 0; j < 5 ; ++j) {
    std::cout << numList[j] << " ";
  }

  return 0;
}