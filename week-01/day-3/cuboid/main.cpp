#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    double a = 3.4;
    double b = 2.9;
    double c = 4.5;

    double surfaceArea = 2 * (a * b + b * c + c * a);
    double volume = a * b * c;

    std::cout << "Surface area: " << surfaceArea << std::endl;
    std::cout << "Volume: " << volume;

    return 0;
}