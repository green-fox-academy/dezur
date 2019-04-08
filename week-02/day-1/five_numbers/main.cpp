#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int array[5];
    int *arrayPointer;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter " << i+1 << ". number!\n";
        std::cin >> array[i];
    }

    for (int j = 0; j < 5; ++j) {
        *arrayPointer = array[j];
        std::cout << *arrayPointer << std::endl;
    }

    return 0;
}