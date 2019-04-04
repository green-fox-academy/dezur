#include <iostream>
#include <string>

int main(int argc, char *args[]) {

  // - Create (dynamically) a two dimensional array
  //   with the following matrix. Use a loop!
  //   by dynamically, we mean here that you can change the size of the matrix
  //   by changing an input value or a parameter or this combined
  //
  //   1 0 0 0
  //   0 1 0 0
  //   0 0 1 0
  //   0 0 0 1
  //
  // - Print this two dimensional array to the output

  int arraySize;

  std::cout << "Enter size of the array:\n";
  std::cin >> arraySize;

  int array[arraySize][arraySize];
  for (int i = 0; i < arraySize; i++) {
    for (int j = 0; j < arraySize; ++j) {
      if (i == j) {
        array[i][j] = 1;
      } else {
        array[i][j] = 0;
      }
    }
  }

  for (int k = 0; k < arraySize; ++k) {
    for (int l = 0; l < arraySize; ++l) {
      std::cout << array[k][l] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}