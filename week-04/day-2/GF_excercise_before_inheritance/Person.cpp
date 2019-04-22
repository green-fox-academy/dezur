//
// Created by Zoli on 2019. 04. 22..
//

#include <iostream>
#include "Person.h"
#include "Student.h"

Person::Person(const std::string &name, unsigned int age, const std::string &gender) : _name(name), _age(age),
                                                                                       _gender(gender) {
    this->_name = name;
    this->_gender = gender;
    this->_age = age;
}

Person::Person() {
    this->_name = "Jane Doe";
    this->_gender = "female";
    this->_age = 30;
}

void Person::introduce(){
    std::cout << "Hi. I'm " << _name << ", a " << _age << " year old " << _gender << ".\n";
}

void Person::getGoal(){
    std::cout << "My goal is: Live for the moment!\n";
}

