//
// Created by Zoli on 2019. 04. 22..
//

#include <iostream>
#include "Station.h"
#include "Car.h"

Station::Station(int gasAmount) : _gasAmount(gasAmount) {
}

void Station::fill(Car car){
    while (!car.isFull()) {
        car.fill();
        std::cout << "Filling car!\n";
        this->_gasAmount--;
    }
    car.isFull();
    std::cout << "Remaining gas amount at the station: " << this->_gasAmount;
}
