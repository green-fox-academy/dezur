//
// Created by Zoli on 2019. 04. 22..
//

#ifndef GF_EXCERCISE_BEFORE_INHERITANCE_PERSON_H
#define GF_EXCERCISE_BEFORE_INHERITANCE_PERSON_H


#include <string>

class Person {
public:
    Person(const std::string &name, unsigned int age, const std::string &gender);
    Person();
    virtual void introduce();
    virtual void getGoal();

protected:
    std::string _name;
    unsigned int _age;
    std::string _gender;

};


#endif //GF_EXCERCISE_BEFORE_INHERITANCE_PERSON_H
