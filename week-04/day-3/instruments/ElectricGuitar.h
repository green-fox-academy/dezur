//
// Created by Zoli on 2019. 04. 24..
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H


#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument{
public:
    ElectricGuitar();
    void play();
    std::string sound();

};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
