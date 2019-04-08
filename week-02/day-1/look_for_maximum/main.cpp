#include <iostream>

int *getBiggest(int *array, int size);

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int size = 0;

    std::cout << "Enter array size: \n";
    std::cin >> size;

    int array[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter " << i + 1 << ". number:\n";
        std::cin >> array[i];
    }

    std::cout << "The biggest number is " << *getBiggest(array, size) << " at address: " << getBiggest(array, size);
    return 0;
}

int *getBiggest(int *array, int size) {
    int max = 0;
    for (int j = 0; j < size; ++j) {
        if (array[j] > array[max])
            max = j;
    }
    return &array[max];
}