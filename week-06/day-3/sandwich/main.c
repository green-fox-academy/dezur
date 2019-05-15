#include <stdio.h>
#include <string.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct
{
    char name[20];
    float price;
    float weight;
} sandwich;

float getPrice(sandwich, int);

int main()
{
    sandwich szendvics1;
    strcpy(szendvics1.name, "Szalamiskenyer");
    szendvics1.price = 1.5;
    szendvics1.weight = 0.1;
    printf("%.1f", getPrice(szendvics1, 5));

    return 0;
}

float getPrice(sandwich food, int pcs)
{
    return food.price * pcs;
}