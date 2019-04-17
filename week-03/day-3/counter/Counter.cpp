//
// Created by Zoli on 2019. 04. 17..
//

#include "Counter.h"
Counter::Counter(int number) : _number(number)
{
    _number = number;
    value = number;
}
Counter::Counter()
{
    _number = 0;
}
int Counter::get() const
{
    return _number;
}
void Counter::SetNumber(int number)
{
    _number = number;
}
void Counter::add(int value)
{
    _number += value;
}
void Counter::add()
{
    _number += 1;
}
void Counter::reset()
{
    _number = value;
}