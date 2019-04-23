//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GF_INHERITANCE_EXERCISE_STUDENT_H
#define GF_INHERITANCE_EXERCISE_STUDENT_H


#include "Person.h"

class Student: public Person {
public:
    Student(const std::string &name, int age, Gender gender, const std::string previousOrganization);
    Student();
    void introduce() override ;
    void getGoal() override;
    void skipDays(int numberOfDays);

private:
    std::string _previousOrganization;
    int _skippedDays = 0;
};


#endif //GF_INHERITANCE_EXERCISE_STUDENT_H
