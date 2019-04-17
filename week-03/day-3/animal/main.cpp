#include <iostream>
#include "Animal.h"

int main()
{
    Animal dog;
    dog.play();
    dog.play();
    dog.play();
    dog.play();
    dog.eat();
    dog.drink();
    std::cout << dog.GetHunger() << std::endl;
    return 0;
}