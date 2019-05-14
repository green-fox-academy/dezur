// Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The stried number is lower
// You found the number: 8
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int storedNumber, guessedNumber;

    storedNumber = rand() % 10;

    while(storedNumber != guessedNumber){
        printf("Enter number: \n");
        scanf("%d", &guessedNumber);
        if (guessedNumber < storedNumber) {
            printf("The stored number is higher\n");
        } else if (guessedNumber > storedNumber){
            printf("The stored number is lower\n");
        } else {
            printf("You found the number: %d\n", storedNumber);
        }
    }
    return 0;
}