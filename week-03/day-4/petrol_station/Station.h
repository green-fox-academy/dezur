//
// Created by Zoli on 2019. 04. 22..
//

#ifndef PETROL_STATION_STATION_H
#define PETROL_STATION_STATION_H


#include "Car.h"

class Station {
public:
    Station(int gasAmount);
    void fill(Car car);

private:
    int _gasAmount;
};


#endif //PETROL_STATION_STATION_H
