//
// Created by Zoli on 2019. 04. 22..
//

#include "Mentor.h"

Mentor::Mentor(const std::string &name, unsigned int age, const std::string &gender, const std::string &level) : Person(
        name, age, gender), _level(level) {
    this->_name = name;
    this->_age = age;
    this->_gender = gender;
    this->_level = level;
}

Mentor::Mentor() {
    this->_name = "Jane Doe";
    this->_age = 30;
    this->_gender = "female";
    this->_level = "intermediate";
}
