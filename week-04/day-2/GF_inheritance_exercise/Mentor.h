//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GF_INHERITANCE_EXERCISE_MENTOR_H
#define GF_INHERITANCE_EXERCISE_MENTOR_H

#include "Person.h"

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor: public Person {
public:
    Mentor(const std::string &name, int age, Gender gender, Level level);
    Mentor();
    void introduce() override ;
    void getGoal() override ;
    std::string levelAsString();

private:
    Level _level;
};


#endif //GF_INHERITANCE_EXERCISE_MENTOR_H
