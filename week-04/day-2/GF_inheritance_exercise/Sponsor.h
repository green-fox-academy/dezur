//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GF_INHERITANCE_EXERCISE_SPONSOR_H
#define GF_INHERITANCE_EXERCISE_SPONSOR_H


#include "Person.h"

class Sponsor : public Person {
public:
    Sponsor(const std::string &name, int age, Gender gender, const std::string &company);

    Sponsor();

    void introduce() override;

    void getGoal() override;
    void hire();

private:
    std::string _company;
    int _hiredStudents;
};


#endif //GF_INHERITANCE_EXERCISE_SPONSOR_H
