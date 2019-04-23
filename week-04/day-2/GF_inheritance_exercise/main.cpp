#include <iostream>
#include "Person.h"

int main() {
    Person person("Zoli", 30, MALE);
    person.introduce();
    person.getGoal();
    return 0;
}