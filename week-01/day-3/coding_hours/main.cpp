#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    int semesterDays = 5 * 17;
    int codingTime = 6 * semesterDays;
    float weeklyHours = 5 * 24;
    float percentage = (52 / weeklyHours) * 100;

    std::cout << "Hours spent with coding: " << codingTime << std::endl;
    std::cout << "Percentage of coding hours: " << percentage << " %";

    return 0;
}