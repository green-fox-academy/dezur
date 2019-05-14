// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
// 
// Surface Area: 600
// Volume: 1000

#include <stdio.h>

int main()
{
    double a, b, c, surfaceArea, volume;
    printf("Enter size A:\n");
    scanf("%lf", &a);
    printf("Enter size B:\n");
    scanf("%lf", &b);
    printf("Enter size C:\n");
    scanf("%lf", &c);

    surfaceArea = 2 * (a * b + b * c + c * a);
    volume = a * b * c;

    printf("Surface area: %.2lf\n", surfaceArea);
    printf("Volume: %.2lf\n", volume);

    return 0;
}