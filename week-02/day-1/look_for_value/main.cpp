#include <iostream>

int look(int array[], int size, int number);

int main() {
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int array[5] = {12, 24, 36, 48, 60};
    int number = 12;
    std::cout << look(array, 5, number);

    return 0;
}

int look(int array[], int size, int number)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] == number){
            return i;
        } else {
            return -1;
        }
    }
}