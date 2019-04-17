//
// Created by Zoli on 2019. 04. 17..
//

#include "Sharpie.h"
Sharpie::Sharpie(const std::string &color, float width, float ink_amount)
    : _color(color), _width(width), _inkAmount(ink_amount)
{}
Sharpie::Sharpie(const std::string &color, float width)
    : _color(color), _width(width)
{
    _inkAmount = 100;
}
const std::string &Sharpie::GetColor() const
{
    return _color;
}
float Sharpie::GetWidth() const
{
    return _width;
}
float Sharpie::GetInkAmount() const
{
    return _inkAmount;
}
void Sharpie::SetColor(const std::string &color)
{
    _color = color;
}
void Sharpie::SetWidth(float width)
{
    _width = width;
}
void Sharpie::SetInkAmount(float ink_amount)
{
    _inkAmount = ink_amount;
}

void Sharpie::use(){
    _inkAmount -= 1;
}
