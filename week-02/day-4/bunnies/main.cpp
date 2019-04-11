#include <iostream>

int ears = 0;

int countEars(int);

int main()
{
    int numberOfBunnies;
    std::cout << "Enter number of bunnies" << std::endl;
    std::cin >> numberOfBunnies;
    std::cout << numberOfBunnies << " bunnies has " << countEars(numberOfBunnies) << " ears";

    return 0;
}

int countEars(int a)
{
    if (ears / 2 == a) {
        return ears;
    } else {
        ears += 2;
        countEars(a);
    }
}