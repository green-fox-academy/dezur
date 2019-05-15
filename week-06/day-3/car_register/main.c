#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum type
{
    MANUAL, AUTOMATIC, CVT, SEMIAUTOMATIC, DUALCLUTCH
};

typedef struct
{
    char name[256];
    float price;
    int yearOfManufacture;
    enum type transmissionType;
} car;

int get_older_cars_than(car cars[], int array_length, int age);
int get_transmission_count(car cars[], int array_length, enum type trnsm);

int main()
{
    car cars[3];

    strcpy(cars[0].name, "Audi A3 2.0TDI");
    cars[0].price = 7373.0;
    cars[0].yearOfManufacture = 2009;
    cars[0].transmissionType = MANUAL;

    strcpy(cars[1].name, "Suzuki Swift");
    cars[1].price = 307.0;
    cars[1].yearOfManufacture = 1994;
    cars[1].transmissionType = MANUAL;

    strcpy(cars[2].name, "Tesla Model 3");
    cars[2].price = 58635.0;
    cars[2].yearOfManufacture = 2019;
    cars[2].transmissionType = AUTOMATIC;

    int size = sizeof(cars) / sizeof(car);

    printf("Older than 10 years cars: %d\n", get_older_cars_than(cars, size, 10));
    printf("Manual transmission cars: %d\n", get_transmission_count(cars, size, MANUAL));

    return 0;
}

int get_older_cars_than(car *cars, int array_length, int age)
{
    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (2019 - cars[i].yearOfManufacture > 10)
            counter++;
    }
    return counter;
}
int get_transmission_count(car *cars, int array_length, enum type trnsm)
{
    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (cars[i].transmissionType == trnsm)
            counter++;
    }
    return counter;
}
