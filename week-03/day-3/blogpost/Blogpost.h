//
// Created by Zoli on 2019. 04. 17..
//

#ifndef BLOGPOST__BLOGPOST_H_
#define BLOGPOST__BLOGPOST_H_

#include <iostream>

class Blogpost {
 public:
    Blogpost(std::string author_name, std::string title, std::string text, std::string publication_date);
    std::string GetAuthorName();
    std::string GetTitle();
    std::string GetText();
    std::string GetPublicationDate();
    void SetAuthorName(std::string author_name);
    void SetTitle(std::string title);
    void SetText(std::string text);
    void SetPublicationDate(std::string publication_date);
 private:
    std::string _authorName;
    std::string _title;
    std::string _text;
    std::string _publicationDate;
};

#endif //BLOGPOST__BLOGPOST_H_
