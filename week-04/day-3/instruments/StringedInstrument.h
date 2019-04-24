//
// Created by Zoli on 2019. 04. 24..
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H


#include "Instrument.h"

class StringedInstrument : public Instrument {
public:
    virtual void sound() = 0;

private:
    int _strings;
    std::string _sounds;
public:
    void setStrings(int strings);

    void setSounds(const std::string &sounds);
};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
