//
// Created by Zoli on 2019. 04. 17..
//

#include "Postit.h"

Postit::Postit(std::string background_color, std::string text, std::string text_color)
{
    setBackgroundColor(background_color);
    setText(text);
    setTextColor(text_color);
}
void Postit::setBackgroundColor(const std::string &backgroundColor)
{
    _backgroundColor = backgroundColor;
}

void Postit::setText(const std::string &text)
{
    _text = text;
}

void Postit::setTextColor(const std::string &textColor)
{
    _textColor = textColor;
}
const std::string &Postit::GetBackgroundColor() const
{
    return _backgroundColor;
}
const std::string &Postit::GetText() const
{
    return _text;
}
const std::string &Postit::GetTextColor() const
{
    return _textColor;
}
