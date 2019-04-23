//
// Created by Zoli on 2019. 04. 23..
//

#include "Student.h"

Student::Student(const std::string &name, int age, Gender gender, const std::string previousOrganization) : Person(
        name, age, gender) {
    _previousOrganization = previousOrganization;
}

Student::Student() {
}

void Student::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << getGender() << " from "
              << _previousOrganization << " who skipped " << _skippedDays << " days from the course already.\n";
}

void Student::getGoal() {
    std::cout << "My goal is: Be a junior software developer.\n";
}

void Student::skipDays(int numberOfDays){
    _skippedDays += numberOfDays;
}
