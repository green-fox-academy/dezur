#include <iostream>
#include "Blogpost.h"

int main()
{
    Blogpost post1("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    Blogpost post2("Wait but why", "Tim Urban", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    Blogpost post3("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.", "2017.03.28.");
    std::cout << post1.GetTitle() << std::endl;
    std::cout << post1.GetText() << std::endl;
    std::cout << post1.GetAuthorName() << std::endl;
    std::cout << post1.GetPublicationDate();
    return 0;
}