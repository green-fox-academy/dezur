//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GARDEN_APP_FLOWER_H
#define GARDEN_APP_FLOWER_H


#include "Plant.h"

class Flower: public Plant {
public:
    Flower(Type plantType, const std::string &color);

};


#endif //GARDEN_APP_FLOWER_H
