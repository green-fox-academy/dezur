// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

int main()
{
    int radius;

    printf("Enter radius:\n");
    scanf("%d", &radius);
    printf("Surface: %.2f\n", getArea(radius));
    printf("Circumference: %.2f\n", getCircumference(radius));
    return 0;
}