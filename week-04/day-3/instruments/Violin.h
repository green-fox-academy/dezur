//
// Created by Zoli on 2019. 04. 24..
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H


#include "StringedInstrument.h"

class Violin : public StringedInstrument{
public:
    Violin();
    void play();
    std::string sound();

};


#endif //INSTRUMENTS_VIOLIN_H
