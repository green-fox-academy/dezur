//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GARDEN_APP_GARDEN_H
#define GARDEN_APP_GARDEN_H


#include <string>
#include <vector>
#include "Plant.h"

class Garden {
public:
    Garden(const std::string &name);
    void addPlant(Plant*);
    void status();
    void watering(int);

private:
    std::string _name;
    std::vector<Plant*> _plants;
};


#endif //GARDEN_APP_GARDEN_H
