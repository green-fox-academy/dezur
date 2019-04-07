#include <iostream>
#include <string>

std::string unique(int a[],int b);

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    std::cout << unique(numbers, 8);
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}

std::string unique(int a[],int b) {
  int hinyje[b];
  int hinyje_size = 0;
  std::string result = "";
  for (int i = 0; i < b ; ++i) {
    bool found = false;
    for (int j = 0; j < hinyje_size ; ++j) {
      if (a[i] == hinyje[j]) {
        found = true;
      }
    }
    if (!found) {
      hinyje[hinyje_size] = a[i];
      hinyje_size++;
    }
  }
  for (int k = 0; k < hinyje_size; ++k) {
    result += std::to_string(hinyje[k]);
    result += " ";

  }
  return result;

}