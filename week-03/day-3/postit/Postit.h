//
// Created by Zoli on 2019. 04. 17..
//

#ifndef POSTIT__POSTIT_H_
#define POSTIT__POSTIT_H_

#include <iostream>
#include <string>

class Postit {
 public:
    Postit(std::string background_color, std::string text, std::string text_color);
    void setBackgroundColor(const std::string &background_color);
    void setText(const std::string &text);
    void setTextColor(const std::string &text_color);
    const std::string &GetBackgroundColor() const;
    const std::string &GetText() const;
    const std::string &GetTextColor() const;

 private:
    std::string _backgroundColor;
    std::string _text;
    std::string _textColor;
};

#endif //POSTIT__POSTIT_H_
