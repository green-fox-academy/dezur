#include <iostream>
#include <math.h>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;
    double BMI;

    // Print the Body mass index (BMI) based on these values

    BMI = massInKg / pow(heightInM, 2);

    std::cout << "BMI index is: " << BMI;

    return 0;
}