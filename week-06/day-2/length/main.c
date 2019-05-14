#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char name[]);
int lengthString(char name[]);

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[20];

    printf("Enter your name\n");
    scanf("%s", name);
    printf("Calculated length without string.h is: %d\n", length(name));
    printf("Calculated length with string.h is: %d\n", lengthString(name));
    return 0;
}

int length(char name[])
{
    int counter = 0;
    while (*(name++) != '\0') {
        counter++;
    }
    return counter;
}

int lengthString(char name[])
{
    return strlen(name);
}