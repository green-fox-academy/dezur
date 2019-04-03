#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;
    int remainingSeconds;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    remainingSeconds = 86400 - currentHours * 3600 + currentMinutes * 60 + currentSeconds;
    std::cout << "Remaining seconds: " << remainingSeconds;


    return 0;
}