#include <stdio.h>
#include <stdlib.h>

int digitEquals(int, int);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    int a, b;

    printf("Enter first number\n");
    scanf("%d", &a);
    printf("Enter second number\n");
    scanf("%d", &b);
    printf("%d", digitEquals(a, b));
    return 0;
}

int digitEquals(int a, int b)
{
    int sumDigitA = 0, sumDigitB = 0, temp, remainder;

    temp = a;
    while (temp != 0)
    {
        remainder = temp % 10;
        sumDigitA = sumDigitA + remainder;
        temp = temp / 10;
    }

    temp = b;
    while (temp != 0)
    {
        remainder = temp % 10;
        sumDigitB = sumDigitB + remainder;
        temp = temp / 10;
    }

    if (sumDigitA == sumDigitB)
        return 1;
    return 0;
}