#include <stdio.h>
#include <string.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct
{
    char address[100];
    int price;
    int numberOfRooms;
    int area;
} house_t;

int doesItWorth(house_t *house);
int countWorth(house_t house[], int size);

int main()
{
    house_t houses[3];

    strcpy(houses[0].address, "2143 Kistarcsa, Mora Ferenc u. 75.");
    houses[0].price = 20348;
    houses[0].numberOfRooms = 2;
    houses[0].area = 60;

    strcpy(houses[0].address, "1101 Budapest, Kiscica u. 18/2/1");
    houses[1].price = 44546;
    houses[1].numberOfRooms = 2;
    houses[1].area = 48;

    strcpy(houses[0].address, "1080 Budapest, Kabitoszer u. 420.");
    houses[2].price = 36898;
    houses[2].numberOfRooms = 1;
    houses[2].area = 30;

    int size = sizeof(houses) / sizeof(house_t);
    printf("%d", countWorth(houses, size));
    
    return 0;
}


int doesItWorth(house_t *house)
{
    if (house->price / house->area < 400)
        return 1;
    else
        return 0;
}

int countWorth(house_t house[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (doesItWorth(&house[i]) == 1)
            counter++;
    }
    return counter;
}