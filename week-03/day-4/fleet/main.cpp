#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    Thing todo1("Get milk");
    fleet.add(todo1);

    Thing todo2("Remove obstacles");
    fleet.add(todo2);

    Thing todo3("Stand up");
    todo3.complete();
    fleet.add(todo3);

    Thing todo4("Eat lunch");
    todo4.complete();
    fleet.add(todo4);


    std::cout << fleet.toString() << std::endl;
    return 0;
}