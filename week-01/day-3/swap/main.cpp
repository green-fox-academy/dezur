#include <iostream>

int main(int argc, char* args[]) {

    // Swap the values of the variables
    int a = 123;
    int b = 526;
    int c;

    c = a;
    a = b;
    b = c;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}