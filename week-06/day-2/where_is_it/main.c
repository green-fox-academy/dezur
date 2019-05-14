#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkCharacter(char myString[], char character);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the 
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    // 
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    // 
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char character;
    char string1[30];

    printf("Enter a word\n");
    scanf("%s", string1);
    printf("Enter a character\n");
    scanf(" %c", &character);
    printf("Position of the character '%c' is: %d\n", character, checkCharacter(string1, character));
    return 0;
}

int checkCharacter(char myString[], char character)
{
    for (int i = 0; myString[i] ; ++i) {
        if (myString[i] == character)
            return i;
    }
    return -1;
}