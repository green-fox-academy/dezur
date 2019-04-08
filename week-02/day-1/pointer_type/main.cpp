#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *aPointer = &a;
    double *bPointer = &b;
    std::string *namePointer = &name;

    std::cout << *aPointer << " is at: " << aPointer << std::endl;
    std::cout << *bPointer << " is at: " << bPointer << std::endl;
    std::cout << *namePointer << " is at: " << namePointer << std::endl;

    return 0;
}