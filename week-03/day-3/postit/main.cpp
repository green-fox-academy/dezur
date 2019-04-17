#include <iostream>
#include "Postit.h"

int main()
{
    Postit Postit1("orange", "Idea1", "blue");
    Postit Postit2("pink", "Awesome", "black");
    Postit Postit3("yellow", "Superb!", "green");
    std::cout << Postit1.GetBackgroundColor() << std::endl;
    std::cout << Postit2.GetText() << std::endl;
    std::cout << Postit3.GetTextColor() << std::endl;
    return 0;
}