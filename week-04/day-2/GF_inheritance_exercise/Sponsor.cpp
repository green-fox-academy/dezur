//
// Created by Zoli on 2019. 04. 23..
//

#include "Sponsor.h"

Sponsor::Sponsor(const std::string &name, int age, Gender gender, const std::string &company, int hiredStudents)
        : Person(name, age, gender), _company(company), _hiredStudents(hiredStudents) {}

Sponsor::Sponsor() {
    setName("Jane Doe");
    setAge(30);
    setGender(FEMALE);
    _company = "Google";
    _hiredStudents = 0;
}

void Sponsor::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << genderToString()
}
