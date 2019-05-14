#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int numA = 22;
    int numB = 13;
    int result;

    result = numA + numB;
    printf("%d\n", result);

    result = numA - numB;
    printf("%d\n", result);

    result = numA * numB;
    printf("%d\n", result);

    result = numA / numB;
    printf("%d\n", result);

    result = numA % numB;
    printf("%d\n", result);

    return 0;
}