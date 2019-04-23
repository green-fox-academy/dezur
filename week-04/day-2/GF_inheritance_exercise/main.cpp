#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {
    Person person("Zoli", 30, MALE);
    person.introduce();
    person.getGoal();

    Student student("Bela", 21, MALE, "ELTE");
    student.skipDays(4);
    student.introduce();
    student.getGoal();
    return 0;
}