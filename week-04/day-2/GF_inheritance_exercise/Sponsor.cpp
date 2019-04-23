//
// Created by Zoli on 2019. 04. 23..
//

#include "Sponsor.h"

Sponsor::Sponsor(const std::string &name, int age, Gender gender, const std::string &company)
        : Person(name, age, gender), _company(company) {
    _hiredStudents = 0;
}

Sponsor::Sponsor() {
    setName("Jane Doe");
    setAge(30);
    setGender(FEMALE);
    _company = "Google";
    _hiredStudents = 0;
}

void Sponsor::introduce() {
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << genderToString() << " who represents "
              << _company << " and hired " << _hiredStudents << " so far.\n";
}

void Sponsor::getGoal() {
    std::cout << "My goal is: Hire brilliant junior software developers.\n";
}

void Sponsor::hire(){
    _hiredStudents++;
}