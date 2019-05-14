#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkString(char string1[], char string2[]);

main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char string1[256], string2[256];

    printf("Enter first string\n");
    scanf("%s", string1);
    printf("Enter second string\n");
    scanf("%s", string2);
    printf("%d", checkString(string1, string2));
    return 0;
}

int checkString(char string1[], char string2[])
{
    printf("%s\n", string1);
    if (strlen(string1) == strlen(string2)) {
        for (int i = 0; string1[i]; i++) {
            string1[i] = tolower(string1[i]);
            string2[i] = tolower(string2[i]);
            if (string1[i] != string2[i])
                return 0;
        }
        return 1;
    } else {
        return 0;
    }
}