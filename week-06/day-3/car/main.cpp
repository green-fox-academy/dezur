#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type
{
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car
{
    enum car_type type;
    double km;
    double gas;
};

void getCarStats(car);

int main()
{
    struct car car1;
    struct car car2;
    struct car car3;
    struct car car4;

    car1.type = VOLVO;
    car1.km = 342670;
    car1.gas = 50;

    car2.type = TOYOTA;
    car2.km = 123562;
    car2.gas = 12;

    car3.type = LAND_ROVER;
    car3.km = 739846;
    car3.gas = 73;

    car4.type = TESLA;
    car4.km = 43793;
    car4.gas = -1;

    getCarStats(car1);
    getCarStats(car2);
    getCarStats(car3);
    getCarStats(car4);

    return 0;
}

void getCarStats(car car)
{

    switch (car.type) {
        case VOLVO:
            printf("%s | km: %.0f, gas level: %.0f\n", "Volvo", car.km, car.gas);
            break;
        case TOYOTA:
            printf("%s | km: %.0f, gas level: %.0f\n", "Toyota", car.km, car.gas);
            break;
        case LAND_ROVER:
            printf("%s | km: %.0f, gas level: %.0f\n", "Land Rover", car.km, car.gas);
            break;
        case TESLA:
            printf("%s | km: %.0f\n", "Tesla", car.km);
            break;
    }
}