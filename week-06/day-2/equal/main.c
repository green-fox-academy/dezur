#include <stdio.h>
#include <stdlib.h>

int isEqual(int a, int b);

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int a, b;
    printf("Enter first number\n");
    scanf("%d", &a);
    printf("Enter second number\n");
    scanf("%d", &b);
    if (isEqual(a, b) == 1){
        printf("Equal");
    } else {
        printf("Non equal");
    }

    return 0;
}

int isEqual(int a, int b)
{
    if (a==b)
        return 1;
    return 0;
}