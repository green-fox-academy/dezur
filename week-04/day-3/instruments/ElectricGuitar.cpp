//
// Created by Zoli on 2019. 04. 24..
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar()
{
    setStrings(6);
    setSounds("Twang");
    _name = "Electric guitar";
}

ElectricGuitar::ElectricGuitar(int numOfStrings)
{
    setStrings(numOfStrings);
    setSounds("Twang");
    _name = "Electric guitar";
};

void ElectricGuitar::play()
{
    std::cout << _name << ", a " << getStrings() << "-stringed instrument that goes " << sound() << std::endl;
}

std::string ElectricGuitar::sound()
{
    return getSounds();
}
