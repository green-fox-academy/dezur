#include <iostream>

//  Create a function that takes two strings as a parameter
//  Returns the starting index where the second one is starting in the first one
//  Returns `-1` if the second string is not in the first one

int substr(char[] str, char[] keyword) {
  return -1;
}

int main(int argc, char **argv) {
  // Example

  // Should print: '17'
  std::cout << substr("this is what I'm searching in", "searching")) << std::endl;

  // Should print: '-1'
  std::cout << substr("this is what I'm searching in", "not")) << std::endl;
}
