//
// Created by Zoli on 2019. 04. 23..
//

#include "Flower.h"

Flower::Flower(Type plantType, const std::string &color) : Plant(plantType, color) {
    setWaterAbsorb(0.75);
    setWaterNeeded(5);
}
