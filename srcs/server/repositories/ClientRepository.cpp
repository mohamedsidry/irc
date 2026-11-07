#include "../../../include/ClientRepository.hpp"



ClientRepository::ClientRepository(){}



ClientRepository::ClientRepository(const ClientRepository& copy)
{
    for (std::map<std::string, Client*>::const_iterator it = copy.clients.begin(); it != copy.clients.end(); ++it)
    {
        clients[it->first] = new Client(*it->second);
    }
}



ClientRepository& ClientRepository::operator=(const ClientRepository& other)
{
    if (this != &other)
    {
        for (std::map<std::string, Client*>::iterator it = clients.begin();
             it != clients.end(); ++it)
        {
            delete it->second;
        }

        clients.clear();

        for (std::map<std::string, Client*>::const_iterator it = other.clients.begin();
             it != other.clients.end(); ++it)
        {
            clients[it->first] = new Client(*it->second);
        }
    }
    return *this;
}

ClientRepository::~ClientRepository()
{
    for (std::map<std::string, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
        delete it->second;
}




bool ClientRepository::hasClient(const std::string& nickname) const
{
    return clients.find(nickname) != clients.end();
}


const Client& ClientRepository::getClient(const std::string& nickname) const
{
    std::map<std::string, Client*>::const_iterator  client = clients.find(nickname);
    if (client == clients.end())
        throw IllegalArgumentException("No client known by " + nickname + " here");
    return *client->second;
}


Client* ClientRepository::addClient(Client* client)
{
    std::pair<std::map<std::string, Client*>::iterator, bool> result;

    result = clients.insert(std::make_pair(client->getNickName(), client));

    if (result.second == false)
        throw IllegalArgumentException( client->getNickName() + " already used");
    return client;
}


void ClientRepository::removeClient(const std::string& nickname)
{
    std::map<std::string, Client*>::iterator it = clients.find(nickname);

    if (it != clients.end())
    {
        delete it->second;
        clients.erase(it);
    }
}

const std::map<std::string, Client *>& ClientRepository::getAllClient(void) const
{
    return this->clients;
}

