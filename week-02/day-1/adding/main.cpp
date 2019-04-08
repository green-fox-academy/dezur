#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;
    int c;

    int *aPtr = &a;
    int *bPtr = &b;

    c = *aPtr + *bPtr;

    std::cout << c;

    return 0;
}