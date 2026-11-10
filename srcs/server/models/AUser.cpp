#include "AUser.hpp"



AUser::AUser(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser):
nickName(nickname),
userName(username),
hostName(hostname),
hostUser(hostuser)
{}



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

void AUser::setNickName(const std::string& nickname){this->nickName = nickname;}
void AUser::setUserName(const std::string& username){this->userName = username;}
void AUser::setHostName(const std::string& hostname){this->hostName = hostname;}
void AUser::setHostUser(const std::string& hostuser){this->hostUser = hostuser;}


bool AUser::operator==(const AUser& other) const
{
    return this->nickName == other.nickName ;
}

bool AUser::operator!=(const AUser& other) const
{
    return (!(*this == other));
}
