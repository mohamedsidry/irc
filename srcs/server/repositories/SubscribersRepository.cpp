#include "Subscriber.hpp"
#include "SubscribersRepository.hpp"
#include "IllegalArgumentException.hpp"

SubscribersRepository::SubscribersRepository()
{}

SubscribersRepository::SubscribersRepository(const SubscribersRepository& copy)
{
    for (SubscribersRepository::const_iterator it = copy.subscribers.begin(); it != copy.subscribers.end(); ++it)
        subscribers[it->first] = it->second;
}

SubscribersRepository& SubscribersRepository::operator=(const SubscribersRepository& other)
{
    if (this != &other)
    {
        subscribers.clear();
        for (SubscribersRepository::const_iterator it = other.subscribers.begin(); it != other.subscribers.end(); ++it)
            subscribers[it->first] = it->second;
    }
    return *this;
}
SubscribersRepository::~SubscribersRepository(){}

void SubscribersRepository::add(AUser* user)
{
    Subscriber *subscriber = NULL;
    if (!user)
        return;
    subscriber = dynamic_cast<Subscriber*>(user);
    if (!subscriber)
        throw IllegalArgumentException("Adding user to subscribers which is not of type Subscriber");
    subscribers.insert(std::make_pair(subscriber->getNickName(), subscriber));
}


void SubscribersRepository::remove(const std::string& nickname)
{
    SubscribersRepository::iterator it = subscribers.find(nickname);
    if (it != subscribers.end())
        subscribers.erase(it);
}


bool SubscribersRepository::rename( const std::string& oldNickName, const std::string& newNickName)
{
    SubscribersRepository::iterator target = subscribers.find(oldNickName);
    if (oldNickName == newNickName)
        return true;
    if (target == subscribers.end())
        return false;
    Subscriber* subscriber = target->second;
    subscribers.insert(std::make_pair(newNickName, subscriber));
    subscriber->setNickName(newNickName);
    subscribers.erase(target);
    return true;

}
bool SubscribersRepository::has(const std::string& nickname) const
{
    return subscribers.find(nickname) != subscribers.end();
}


std::size_t SubscribersRepository::size(void) const
{
    return subscribers.size();
}

