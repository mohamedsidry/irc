#include "Subscriber.hpp"
#include "SubscribersService.hpp"
#include "IUserManagement.hpp"
#include "IllegalArgumentException.hpp"
#include "Utils.hpp"
#include "Config.hpp"

SubscribersService::SubscribersService(IUserManagement& repo):
repository(repo)
{}



void SubscribersService::addSubscriber(Subscriber *subscriber)
{
    if (!subscriber)
        return;
    repository.add(subscriber);
}

void SubscribersService::removeSubscriber(const std::string& nickname)
{
    if (repository.has(nickname))
        repository.remove(nickname);
    else
        throw IllegalArgumentException("No Subscriber known by " + nickname);
}


void SubscribersService::renameSubscriber(const std::string& oldNickName, const std::string& newNickName)
{
    if (newNickName.empty() || Utils::isAllWhitespace(newNickName))
        throw IllegalArgumentException("Empty nickname");
    if (newNickName.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + newNickName);
    if (!repository.has(oldNickName))
        throw IllegalArgumentException("No Subscriber known by " + oldNickName);
    if (repository.has(newNickName))
        throw IllegalArgumentException(newNickName + " Already in use try an other nickname");
    repository.rename(oldNickName, newNickName);
}


bool SubscribersService::hasSubscriber(const std::string& nickname) const
{
    return repository.has(nickname);
}
