#include <iostream>

int result = 1;

int powerN(int, int);

int main()
{
    int base;
    int power;
    std::cout << "Enter number" << std::endl;
    std::cin >> base;
    std::cout << "Enter power" << std::endl;
    std::cin >> power;
    std::cout << powerN(base, power);
    return 0;
}

int powerN(int a, int b)
{
    if (b < 1) {
        return result;
    } else {
        result *= a;
        --b;
        powerN(result, b);
    }
}