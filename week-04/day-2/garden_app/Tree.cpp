//
// Created by Zoli on 2019. 04. 23..
//

#include "Tree.h"

Tree::Tree(Type plantType, const std::string &color) : Plant(plantType, color) {
    setWaterAbsorb(0.4);
    setWaterNeeded(10);
}
