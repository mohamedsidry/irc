#include <ostream>
#include "AUser.hpp"
#include "Config.hpp"
#include "Utils.hpp"
#include "IllegalArgumentException.hpp"

AUser::AUser(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser):
nickName(nickname),
userName(username),
hostName(hostname),
hostUser(hostuser)
{
    if (nickname.empty() || Utils::isAllWhitespace(nickname))
        throw IllegalArgumentException("Empty nickname");
    if (nickname.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + nickname);
}



AUser::AUser(const AUser& copy):
nickName(copy.nickName),
userName(copy.userName),
hostName(copy.hostName),
hostUser(copy.hostUser)
{}

AUser& AUser::operator=(const AUser& other)
{
    if (this != &other)
    {
        this->nickName = other.nickName;
        this->userName = other.userName;
        this->hostName = other.hostName;
        this->hostUser = other.hostUser;
    }
    return (*this);
}


AUser::~AUser(){}



/** 
* @note getters and setters .
*/


const std::string& AUser::getNickName(void) const {return this->nickName;}
const std::string& AUser::getUserName(void) const {return this->userName;}
const std::string& AUser::getHostName(void) const {return this->hostName;}
const std::string& AUser::getHostUser(void) const {return this->hostUser;}

void AUser::setNickName(const std::string& nickname)
{
    if (nickname.empty() || Utils::isAllWhitespace(nickname))
        throw IllegalArgumentException("Empty nickname");
    if (nickname.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + nickname);
    this->nickName = nickname;
}
void AUser::setUserName(const std::string& username){this->userName = username;}


bool AUser::operator==(const AUser& other) const
{
    return this->nickName == other.nickName ;
}

bool AUser::operator!=(const AUser& other) const
{
    return (!(*this == other));
}


std::ostream& operator<<(std::ostream& os, const AUser& user)
{
    os << "CLIENT NICKNAME : " << user.getNickName() << "\n";
    os << "CLIENT USERNAME : " << user.getUserName() << "\n";
    os << "CLIENT HOSTNAME : " << user.getHostName() << "\n";
    os << "CLIENT HOSTUSER : " << user.getHostUser() << "\n";
    return os;
}
