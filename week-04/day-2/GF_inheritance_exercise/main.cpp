#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Mentor.h"
#include "Sponsor.h"

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

    Sponsor sponsor;
    sponsor.hire();
    sponsor.introduce();
    sponsor.getGoal();
    return 0;
}