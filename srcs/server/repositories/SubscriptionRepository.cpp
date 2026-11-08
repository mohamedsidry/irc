
#include "SubscriptionRepository.hpp"
#include "Client.hpp"
#include "IllegalArgumentException.hpp"



SubscriptionRepository::SubscriptionRepository(){}




SubscriptionRepository::SubscriptionRepository(const SubscriptionRepository& copy)
{
    for (std::map<std::string, Client*>::const_iterator it = copy.clients.begin(); it != copy.clients.end(); ++it)
    {
        clients[it->first] = it->second;
    }
}



SubscriptionRepository& SubscriptionRepository::operator=(const SubscriptionRepository& other)
{
    if (this != &other)
    {

        clients.clear();
        for (std::map<std::string, Client*>::const_iterator it = other.clients.begin();
             it != other.clients.end(); ++it)
        {
            clients[it->first] = it->second;
        }
    }
    return *this;
}

SubscriptionRepository::~SubscriptionRepository(){}




bool SubscriptionRepository::hasClient(const std::string& nickname) const
{
    return clients.find(nickname) != clients.end();
}


Client* SubscriptionRepository::getClient(const std::string& nickname)
{
    std::map<std::string, Client*>::const_iterator  client = clients.find(nickname);
    if (client == clients.end())
        throw IllegalArgumentException("No subscriber known by " + nickname);
    return client->second;
}


Client* SubscriptionRepository::addClient(Client* client)
{
    std::pair<std::map<std::string, Client*>::iterator, bool> result;

    result = clients.insert(std::make_pair(client->getNickName(), client));

    if (result.second == false)
        throw IllegalArgumentException( client->getNickName() + " already Subscribed");
    return client;
}


void SubscriptionRepository::removeClient(const std::string& nickname)
{
    std::map<std::string, Client*>::iterator it = clients.find(nickname);

    if (it != clients.end())
        clients.erase(it);
}

const std::map<std::string, Client *>& SubscriptionRepository::getAllClient(void) const
{
    return this->clients;
}


void SubscriptionRepository::removeAll(void)
{
    clients.clear();
}
