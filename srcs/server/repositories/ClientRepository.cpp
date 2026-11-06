#include "../../../include/ClientRepository.hpp"



ClientRepository::ClientRepository():
ISearchableClient(),
IClientManagment()
{}



ClientRepository::ClientRepository(const ClientRepository& copy):
ISearchableClient(),
IClientManagment(),
clients(copy.clients)
{}





ClientRepository& ClientRepository::operator=(const ClientRepository& other)
{
    if (this != &other)
    {
        IClientManagment::operator=(other);
        ISearchableClient::operator=(other);
        this->clients = other.clients;
    }
    return *this;
}


ClientRepository::~ClientRepository(){}




bool ClientRepository::hasClient(const std::string& nickname) const
{
    return clients.find(nickname) != clients.end();
}


const Client& ClientRepository::getClient(const std::string& nickname) const
{
    std::map<std::string, Client>::const_iterator  client = clients.find(nickname);
    if (client == clients.end())
        throw IllegalArgumentException("No client known by " + nickname + " here");
    return client->second;
}


void ClientRepository::addClient(const Client& client)
{
    if (hasClient(client.getNickName()))
        throw IllegalArgumentException(client.getNickName() + " already used try an other nickname");
    this->clients.insert(std::pair<std::string, Client>(client.getNickName(), client));
}


void ClientRepository::removeClient(const std::string& nickname)
{

    std::map<std::string, Client>::const_iterator  client = clients.find(nickname);
    if (client != clients.end())
        clients.erase(client->first);
}

const std::map<std::string, Client>& ClientRepository::getAllClient(void) const
{
    return this->clients;
}

