//
// Created by Zoli on 2019. 04. 23..
//

#include <iostream>
#include "Person.h"

Person::Person(const std::string &name, int age, Gender gender) : _name(name), _age(age), _gender(gender) {}

Person::Person() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

void Person::introduce(){
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderToString() << ".\n";
}

void Person::getGoal(){
    std::cout << "My goal is: Live for the moment!\n";
}

std::string Person::genderToString(){
    switch(_gender) {
        case MALE:
            return "male";
        case FEMALE:
            return "female";
    }
}

const std::string &Person::getName() const {
    return _name;
}

int Person::getAge() const {
    return _age;
}

Gender Person::getGender() const {
    return _gender;
}
