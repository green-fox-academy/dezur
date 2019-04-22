//
// Created by Zoli on 2019. 04. 22..
//

#ifndef GF_EXCERCISE_BEFORE_INHERITANCE_STUDENT_H
#define GF_EXCERCISE_BEFORE_INHERITANCE_STUDENT_H


#include "Person.h"

class Student: public Person {
public:
    Student(const std::string &name, unsigned int age, const std::string &gender,
            const std::string &previousOrganization);

    Student();
    void getGoal();
    void introduce();
    int skipDays(int);

private:
    std::string _previousOrganization;
    unsigned int _skippedDays;
};


#endif //GF_EXCERCISE_BEFORE_INHERITANCE_STUDENT_H
