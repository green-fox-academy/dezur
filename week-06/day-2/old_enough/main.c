#include <stdio.h>
#include <stdlib.h>

void canBuyAlcohol(int age);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;

    printf("Enter your age:\n");
    scanf("%d", &age);
    canBuyAlcohol(age);

    return 0;
}

void canBuyAlcohol(int age)
{
    if (age < 18){
        printf("You cannot buy alcohol!");
    } else {
        printf("You can buy alcohol!");
    }
}

