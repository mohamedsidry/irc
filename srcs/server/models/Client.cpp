#include "Client.hpp"
#include <iostream>

Client::Client(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser):
AUser(nickname, username, hostname, hostuser)
{}

Client::Client(const Client& copy):
AUser(copy)
{}

Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        AUser::operator=(other);
    }
    return *this;
}


Client::~Client(){}

void Client::showInfo(void) const
{
    std::cout << *this;
}
