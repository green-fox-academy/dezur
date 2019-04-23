//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GF_INHERITANCE_EXERCISE_PERSON_H
#define GF_INHERITANCE_EXERCISE_PERSON_H


#include <string>

enum Gender {
    FEMALE,
    MALE
};

class Person {
public:
    Person(const std::string &name, int age, Gender gender);
    Person();

    void introduce();
    void getGoal();
    std::string genderToString();

private:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GF_INHERITANCE_EXERCISE_PERSON_H
