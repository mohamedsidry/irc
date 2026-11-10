#include "Client.hpp"


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
    std::cout << "CLIENT NICKNAME : " << getNickName() << "\n";
    std::cout << "CLIENT USERNAME : " << getUserName() << "\n";
    std::cout << "CLIENT HOSTNAME : " << getHostName() << "\n";
    std::cout << "CLIENT HOSTUSER : " << getHostUser() << "\n";
}
