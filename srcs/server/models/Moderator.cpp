#include "Moderator.hpp"
#include <iostream>



Moderator::Moderator(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser):
AUser(nickname, username, hostname, hostuser)
{}

Moderator::Moderator(const Moderator& copy):
AUser(copy)
{}

Moderator& Moderator::operator=(const Moderator& other)
{
    if (this != &other)
    {
        AUser::operator=(other);
    }
    return *this;
}


Moderator::~Moderator(){}

void Moderator::showInfo(void) const
{
    std::cout << *this;
}
