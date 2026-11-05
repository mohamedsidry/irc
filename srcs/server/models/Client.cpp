#include "../../../include/Client.hpp"


Client::Client(){}

Client::Client(const Client& copy){(void)copy;}

Client::Client(const std::string& nn, const std::string& un, const std::string& hn, const std::string& hu):
nickName(nn),
userName(un),
hostName(hn),
hostUser(hu)
{}


Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        this->nickName = other.nickName;
        this->userName = other.userName;
        this->hostName = other.hostName;
        this->hostUser = other.hostUser;
    }
    return *this;
}


Client::~Client(){}



/** 
* @note getters .
*/

const std::string& Client::getNickName(void) const
{
    return this->nickName;
}

const std::string& Client::getUserName(void) const
{
    return this->userName;
}

const std::string& Client::getHostName(void) const
{
    return this->hostName;
}
const std::string& Client::getHostUser(void) const
{
    return this->hostUser;
}


bool Client::operator==(const Client& other) const
{
    return this->nickName == other.nickName ;
}

bool Client::operator!=(const Client& other) const
{
    return (!(*this == other));
}



std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "NICK NAME : " << client.getNickName() << std::endl;
    os << "USER NAME : " << client.getUserName() << std::endl;
    os << "HOST NAME : " << client.getHostName() << std::endl;
    os << "HOST USER : " << client.getHostUser() << std::endl;
    return os;
}
