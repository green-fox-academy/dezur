#include <iostream>
#include <fstream>

int main()
{
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0
    try {
        int divider;

        std::cout << "Enter number\n";
        std::cin >> divider;
        if (divider == 0) {
            throw std::string("fail");
        }
        std::cout << 10 / divider << std::endl;
    } catch (std::string& e) {
        std::cout << e << std::endl;
    }

    return 0;
}