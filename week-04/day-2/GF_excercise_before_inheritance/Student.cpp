//
// Created by Zoli on 2019. 04. 22..
//

#include <iostream>
#include "Person.h"
#include "Student.h"

Student::Student(const std::string &name, unsigned int age, const std::string &gender,
                 const std::string &previousOrganization) : Person(name, age, gender),
                                                            _previousOrganization(previousOrganization) {
    this->_skippedDays = 0;
}

Student::Student() {
    Person::_name = "Jane Doe";
    Person::_age = 30;
    Person::_gender = "female";
    this->_previousOrganization = "The School of Life";
    this->_skippedDays = 0;
}

void Student::getGoal() {
    std::cout << "My goal is: Be a junior software developer.\n";
}

void Student::introduce() {
    std::cout << "Hi, I'm " << this->_name << ", a " << this->_age << " year old " << this->_gender << " from "
              << this->_previousOrganization << " who skipped " << this->_skippedDays
              << " days from the course already.\n";
}

int Student::skipDays(int numberOfDays) {
    return this->_skippedDays + numberOfDays;
}