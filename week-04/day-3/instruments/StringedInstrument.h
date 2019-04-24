//
// Created by Zoli on 2019. 04. 24..
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H


#include "Instrument.h"

class StringedInstrument : public Instrument
{
public:
    virtual std::string sound() = 0;
    void setStrings(int strings);
    void setSounds(const std::string &sounds);
    const std::string &getSounds() const;
    int getStrings() const;
private:
    int _strings;
    std::string _sounds;
};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
