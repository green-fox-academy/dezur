#include <iostream>
#include <cmath>

int sum = 0;

int sumdigit(int);

int main()
{
    unsigned int number = 0;
    std::cout << "Enter number" << std::endl;
    std::cin >> number;
    std::cout << sumdigit(number);
    return 0;
}

int sumdigit(int number)
{
    if (number < 1) {
        return sum;
    } else {
        sum = sum + number % 10;
        number = number / 10;
        sumdigit(number);
    }

}