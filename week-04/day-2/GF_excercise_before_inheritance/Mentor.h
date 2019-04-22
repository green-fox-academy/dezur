//
// Created by Zoli on 2019. 04. 22..
//

#ifndef GF_EXCERCISE_BEFORE_INHERITANCE_MENTOR_H
#define GF_EXCERCISE_BEFORE_INHERITANCE_MENTOR_H


#include "Person.h"

class Mentor: public Person {
public:
    Mentor(const std::string &name, unsigned int age, const std::string &gender, const std::string &level);

    Mentor();

private:
    std::string _level;
};


#endif //GF_EXCERCISE_BEFORE_INHERITANCE_MENTOR_H
