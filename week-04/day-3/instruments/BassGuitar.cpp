//
// Created by Zoli on 2019. 04. 24..
//

#include "BassGuitar.h"

BassGuitar::BassGuitar()
{
    setStrings(4);
    setSounds("Duum-duum-dumm");
    _name = "Bass guitar";
}

BassGuitar::BassGuitar(int numOfStrings)
{
    setStrings(numOfStrings);
    setSounds("Duum-duum-dumm");
    _name = "Bass guitar";
}

std::string BassGuitar::sound()
{
    return getSounds();
}

void BassGuitar::play()
{
    std::cout << _name << ", a " << getStrings() << "-stringed instrument that goes " << sound() << std::endl;
}

