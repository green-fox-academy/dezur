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


void Plant::setWaterAbsorb(double waterAbsorb) {
    _waterAbsorb = waterAbsorb;
}

void Plant::setWaterNeeded(int waterNeeded) {
    _waterNeeded = waterNeeded;
}

std::string Plant::getPlantType() const {
    switch (_plantType) {
        case TREE:
            return "tree";
        case FLOWER:
            return "flower";
    }
}

const std::string &Plant::getColor() const {
    return _color;
}

void Plant::increaseWaterLevel(float water) {
    _waterLevel+= water * _waterAbsorb;
}
