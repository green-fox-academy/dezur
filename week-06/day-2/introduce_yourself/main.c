#include<stdio.h>

int main()
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87
    char name[] = "Zoltan Petrenyi";
    int age = 30;
    float height = 1.76;

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f", height);

    return 0;
}