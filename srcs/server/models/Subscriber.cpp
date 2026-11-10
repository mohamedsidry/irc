#include "Subscriber.hpp"



Subscriber::Subscriber(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser):
AUser(nickname, username, hostname, hostuser)
{}

Subscriber::Subscriber(const Subscriber& copy):
AUser(copy)
{}

Subscriber& Subscriber::operator=(const Subscriber& other)
{
    if (this != &other)
    {
        AUser::operator=(other);
    }
    return *this;
}


Subscriber::~Subscriber(){}

void Subscriber::showInfo(void) const
{
    std::cout << "SUBSCRIBER NICKNAME : " << getNickName() << "\n"
    std::cout << "SUBSCRIBER USERNAME : " << getUserName() << "\n"
    std::cout << "SUBSCRIBER HOSTNAME : " << getHostName() << "\n"
    std::cout << "SUBSCRIBER HOSTUSER : " << getHostUser() << "\n"
}