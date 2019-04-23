//
// Created by Zoli on 2019. 04. 23..
//

#include <iostream>
#include "Garden.h"

Garden::Garden(const std::string &name) : _name(name) {
    _plants.clear();
}

void Garden::addPlant(Plant *plant){
    _plants.push_back(plant);
}

void Garden::status(){
    std::string thirstyStatus;
    for (int i = 0; i < _plants.size(); ++i) {
        if (_plants[i]->isThirsty()) {
            thirstyStatus = "needs water";
        } else {
            thirstyStatus = "doesnt need water";
        }
        std::cout << _plants[i]->getColor() << " " << _plants[i]->getPlantType() << " " << thirstyStatus << std::endl;
    }
}

void Garden::watering(int waterAmount){
    std::cout << "Watering with " << waterAmount << std::endl;
    for (int i = 0; i < _plants.size(); ++i) {
        if (_plants[i]->isThirsty()) {
            _plants[i]->watering(waterAmount);
        }
    }
}