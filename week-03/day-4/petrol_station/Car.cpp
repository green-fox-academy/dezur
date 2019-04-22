//
// Created by Zoli on 2019. 04. 22..
//

#include "Car.h"

Car::Car(int gasAmount, int capacity) : _gasAmount(gasAmount), _capacity(capacity) {
    this->_gasAmount = gasAmount;
    this->_capacity = capacity;
}

bool Car::isFull(){
    if (_gasAmount == _capacity){
        return true;
    } else {
        return false;
    }
}

void Car::fill(){
    this->_gasAmount++;
}