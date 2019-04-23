//
// Created by Zoli on 2019. 04. 23..
//

#include "Plant.h"

Plant::Plant(Type plantType, const std::string &color) : _plantType(plantType), _color(color) {
    _waterLevel = 0;
}

bool Plant::isThirsty() {
    if (_waterLevel < _waterNeeded) {
        return true;
    } else {
        return false;
    }
}

void Plant::watering(int waterAmount){
    if (isThirsty()) {
        _waterLevel += waterAmount * _waterAbsorb;
    }
}

void Plant::setWaterAbsorb(double waterAbsorb) {
    _waterAbsorb = waterAbsorb;
}

void Plant::setWaterNeeded(int waterNeeded) {
    _waterNeeded = waterNeeded;
}
