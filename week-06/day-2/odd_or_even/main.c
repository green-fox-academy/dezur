#include <stdio.h>
#include <stdlib.h>

int oddOrEven(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int number;

    printf("Enter a number\n");
    scanf("%d", &number);
    printf("%d", oddOrEven(number));
    return 0;
}

int oddOrEven(int number)
{
    if (number % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}