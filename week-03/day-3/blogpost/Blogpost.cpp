//
// Created by Zoli on 2019. 04. 17..
//

#include "Blogpost.h"
#include <iostream>

Blogpost::Blogpost(std::string author_name, std::string title, std::string text, std::string publication_date)
{
    SetAuthorName(author_name);
    SetTitle(title);
    SetText(text);
    SetPublicationDate(publication_date);
}
std::string Blogpost::GetAuthorName()
{
    return _authorName;
}
std::string Blogpost::GetTitle()
{
    return _title;
}
std::string Blogpost::GetText()
{
    return _text;
}
std::string Blogpost::GetPublicationDate()
{
    return _publicationDate;
}

void Blogpost::SetAuthorName(std::string author_name)
{
    _authorName = author_name;
}
void Blogpost::SetTitle(std::string title)
{
    _title = title;
}
void Blogpost::SetText(std::string text)
{
    _text = text;
}
void Blogpost::SetPublicationDate(std::string publication_date)
{
    _publicationDate = publication_date;
}