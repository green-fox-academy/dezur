//
// Created by Zoli on 2019. 04. 23..
//

#ifndef GARDEN_APP_PLANT_H
#define GARDEN_APP_PLANT_H

#include <string>

enum Type{
    TREE,
    FLOWER
};

class Plant {
public:
    Plant(Type plantType, const std::string &color);
    bool isThirsty();
    void setWaterAbsorb(double waterAbsorb);
    void setWaterNeeded(int waterNeeded);
    std::string getPlantType() const;
    const std::string &getColor() const;
    void increaseWaterLevel(float);

private:
    Type _plantType;
    std::string _color;
    int _waterNeeded;
    double _waterLevel;
    double _waterAbsorb;
};


#endif //GARDEN_APP_PLANT_H
