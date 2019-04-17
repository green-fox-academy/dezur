#include <iostream>
#include "Sharpie.h"
int main()
{
    Sharpie pen("red", 10);
    pen.use();
    pen.use();
    pen.use();
    pen.use();
    std::cout << pen.GetInkAmount() << std::endl;
    return 0;
}