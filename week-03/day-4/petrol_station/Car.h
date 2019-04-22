//
// Created by Zoli on 2019. 04. 22..
//

#ifndef PETROL_STATION_CAR_H
#define PETROL_STATION_CAR_H


class Car {
public:
    Car(int gasAmount, int capacity);
    bool isFull();
    void fill();

private:
    int _gasAmount;
    int _capacity;
};


#endif //PETROL_STATION_CAR_H
