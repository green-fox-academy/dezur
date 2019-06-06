//
// Created by Zoli on 2019. 06. 06..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartphones.h"

int counter = 0;

void read_file(char *file)
{
    smartphones = malloc(256 * sizeof(smartphones));

    FILE *myFile = fopen(file, "r");

    char text[100];

    while (fgets(text, 100, myFile) != NULL) {
        char *token;

        token = strtok(text, " ");
        smartphones[counter].name = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(smartphones[counter].name, token);

        token = strtok(NULL, " ");
        smartphones[counter].release_year = atoi(token);

        token = strtok(NULL, " ");
        if (atoi(token) < 12) {
            smartphones[counter].screen_size = SMALL;
        } else if (atoi(token) >= 12 && atoi(token) < 15) {
            smartphones[counter].screen_size = MEDIUM;
        } else if (atoi(token) >= 15) {
            smartphones[counter].screen_size = BIG;
        }

        counter++;
    }

    fclose(myFile);
}

void write_file(char *file)
{
    FILE *myFile = fopen(file, "w");

    for (int i = 0; i < counter; ++i) {
        int price = 300;
        int years_old;

        switch (smartphones[i].screen_size) {
            case MEDIUM:
                price += 100;
                break;
            case BIG:
                price *= 2;
                break;
        }
        years_old = 2019 - smartphones[i].release_year;
        if (years_old <= 5) {
            price -= years_old * 50;
        } else {
            price -= 250;
        }

        fprintf(myFile, "%s %d\n", smartphones[i].name, price);
    }

    fclose(myFile);
}

char *get_oldest_phone()
{
    int oldest, actual_year, oldest_year = 2019;

    for (int i = 0; i < counter; ++i) {
        actual_year = smartphones[i].release_year;
        if (actual_year < oldest_year) {
            oldest_year = actual_year;
            oldest = i;
        }
    }

    return smartphones[oldest].name;
}

int get_screen_size_count(screen scr)
{
    int cnt = 0;

    for (int i = 0; i < counter; ++i) {
        if (smartphones[i].screen_size == scr) {
            cnt++;
        }
    }

    return cnt;
}