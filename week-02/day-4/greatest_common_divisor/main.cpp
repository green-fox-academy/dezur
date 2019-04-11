#include <iostream>

int gcd(int a, int b);

int main()
{
    int firstNumber;
    int secondNumber;
    std::cout << "Enter first number" << std::endl;
    std::cin >> firstNumber;
    std::cout << "Enter second number" << std::endl;
    std::cin >> secondNumber;
    std::cout << "Greatest common divisor is: " << gcd(firstNumber, secondNumber);
    return 0;
}

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a-b, b);
    else return gcd(a, b-a);
}