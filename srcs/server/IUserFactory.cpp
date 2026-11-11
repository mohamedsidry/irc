#include "IUserFactory.hpp"
#include "AUser.hpp"
#include "Client.hpp"
#include "Subscriber.hpp"
#include "Moderator.hpp"



AUser* IUserFactory::createUser(const std::string& type, const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser)
{
    if (type == "Client")
        return new Client(nickname, username, hostname, hostuser);
    else if (type == "Subscriber")
        return new Subscriber(nickname, username, hostname, hostuser);
    else if (type == "Moderator")
        return new Moderator(nickname, username, hostname, hostuser);
    else
        return NULL;
}

