#include <iostream>
#include "Station.h"

int main() {
    Station OMW(500);
    Car audi(5, 60);
    Car volvo(15, 50);
    Car suzuki(2, 30);
    Car opel(19, 40);
    Car volkswagen(30, 60);

    OMW.fill(audi);
    OMW.fill(volvo);
    OMW.fill(suzuki);
    OMW.fill(opel);
    OMW.fill(volkswagen);
    return 0;
}