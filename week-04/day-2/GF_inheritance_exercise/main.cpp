#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Mentor.h"

int main() {
    Person person;
    person.introduce();
    person.getGoal();

    Student student;
    student.skipDays(4);
    student.introduce();
    student.getGoal();

    Mentor mentor;
    mentor.introduce();
    mentor.getGoal();
    return 0;
}