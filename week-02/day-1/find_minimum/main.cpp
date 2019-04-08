#include <iostream>
#include <algorithm>

int *findMinimum (int a[], int b);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    std::cout << &numbers[5] << std::endl;
    std::cout << "Minimum value is: " << *findMinimum(numbers,7) << " at address: " << findMinimum(numbers, 7);
    return 0;
}

int *findMinimum (int a[], int b){

    int min = 0;

    for( int i = 0; i < b; i++ )
    {
        if( a[i] < a[min] )
        {
            min = i;
        }
    }

    return a + min;


}