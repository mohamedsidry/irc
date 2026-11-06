#include "../../../include/Client.hpp"

size_t Client::NICKNAME_MAX_SIZE = 9;

Client::Client(){}

Client::Client(const Client& copy){(void)copy;}

Client::Client(const std::string& nn, const std::string& un, const std::string& hn, const std::string& hu)
{
    if (nn.empty() || Utils::isAllWhitespace(nn))
        throw IllegalArgumentException("Empty nickname");
    if (nn.size() > Client::NICKNAME_MAX_SIZE)
        throw IllegalArgumentException("Too Long nickname");
    this->nickName = nn;
    this->userName = un;
    this->hostName = hn;
    this->hostUser = hu;
}


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
