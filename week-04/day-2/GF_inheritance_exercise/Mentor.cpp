//
// Created by Zoli on 2019. 04. 23..
//

#include "Mentor.h"

Mentor::Mentor(const std::string &name, int age, Gender gender, Level level) : Person(name, age, gender),
                                                                               _level(level) {}

Mentor::Mentor() {
    setName("Jane Doe");
    setAge(30);
    setGender(FEMALE);
    _level = INTERMEDIATE;
}

void Mentor::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " years old " << genderToString() << " "
              << levelAsString() << " level mentor.\n";
}

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junior software developers.\n";
}

std::string Mentor::levelAsString() {
    switch (_level) {
        case JUNIOR:
            return "junior";
        case INTERMEDIATE:
            return "intermediate";
        case SENIOR:
            return "senior";
    }
}
