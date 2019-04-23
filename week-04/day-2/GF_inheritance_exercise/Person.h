//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GF_INHERITANCE_EXERCISE_PERSON_H
#define GF_INHERITANCE_EXERCISE_PERSON_H


#include <string>
#include <iostream>

enum Gender {
    FEMALE,
    MALE
};

class Person {
public:
    Person(const std::string &name, int age, Gender gender);
    Person();

    virtual void introduce();
    virtual void getGoal();
    std::string genderToString();

    const std::string &getName() const;
    int getAge() const;
    Gender getGender() const;

private:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GF_INHERITANCE_EXERCISE_PERSON_H
