//
// Created by Zoli on 2019. 04. 23..
//

#include "Garden.h"

Garden::Garden(const std::string &name) : _name(name) {
    _plants.clear();
}

void Garden::addPlant(Plant *plant){
    _plants.push_back(plant);
}