#include <iostream>

int adder(int n);

int main()
{
    int number = 0;
    std::cout << "Enter number:" << std::endl;
    std::cin >> number;
    std::cout << adder(number);
    return 0;
}

int adder(int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n + adder(n - 1);
    }
}