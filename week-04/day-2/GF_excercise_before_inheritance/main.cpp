#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {
    Person nilcsi("Barish Virag Nilofer", 27, "female");
    nilcsi.introduce();
    nilcsi.getGoal();

    Student zoli("Petrenyi Zoltan", 30, "male", "Greenfox");
    zoli.introduce();
    zoli.getGoal();
    std::cout << zoli.skipDays(5);

    return 0;
}