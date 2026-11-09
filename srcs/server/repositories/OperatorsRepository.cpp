
#include "OperatorsRepository.hpp"
#include "Client.hpp"
#include "IllegalArgumentException.hpp"



OperatorsRepository::OperatorsRepository(){}




OperatorsRepository::OperatorsRepository(const OperatorsRepository& copy)
{
    for (std::map<std::string, Client*>::const_iterator it = copy.clients.begin(); it != copy.clients.end(); ++it)
    {
        clients[it->first] = it->second;
    }
}



OperatorsRepository& OperatorsRepository::operator=(const OperatorsRepository& other)
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

OperatorsRepository::~OperatorsRepository(){}




bool OperatorsRepository::hasClient(const std::string& nickname) const
{
    return clients.find(nickname) != clients.end();
}


Client* OperatorsRepository::getClient(const std::string& nickname)
{
    std::map<std::string, Client*>::const_iterator  client = clients.find(nickname);
    if (client == clients.end())
        throw IllegalArgumentException("No Operator known by " + nickname);
    return client->second;
}


Client* OperatorsRepository::addClient(Client* client)
{
    std::pair<std::map<std::string, Client*>::iterator, bool> result;

    result = clients.insert(std::make_pair(client->getNickName(), client));

    if (result.second == false)
        throw IllegalArgumentException(client->getNickName() + " already Operator");
    return client;
}


void OperatorsRepository::removeClient(const std::string& nickname)
{
    std::map<std::string, Client*>::iterator it = clients.find(nickname);

    if (it != clients.end())
        clients.erase(it);
}

const std::map<std::string, Client *>& OperatorsRepository::getAllClient(void) const
{
    return this->clients;
}


void OperatorsRepository::removeAll(void)
{
    clients.clear();
}
