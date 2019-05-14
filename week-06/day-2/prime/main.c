#include <stdio.h>
#include <stdlib.h>

int isPrime(int number);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int number;

    printf("Enter a number\n");
    scanf("%d", &number);
    if (isPrime(number) == 1)
        printf("prime number\n");
    else
        printf("non-prime number\n");
    return 0;
}

int isPrime(int number)
{
    int flag = 0;
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        return 1;
    else
        return 0;
}

