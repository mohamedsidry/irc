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
    for (std::list<Client>::const_iterator it = clients.begin(); it != clients.end(); it++)
        if (nickname == it->getNickName())
            return true;
    return false;
}


const Client& ClientRepository::getClient(const std::string& nickname) const
{
    for (std::list<Client>::const_iterator it = clients.begin(); it != clients.end(); it++)
        if (nickname == it->getNickName())
            return *it;
    throw IllegalArgumentException("No client known by " + nickname + " here");
}


void ClientRepository::addClient(const Client& client)
{
    if (hasClient(client.getNickName()))
        throw IllegalArgumentException(client.getNickName() + " already used try an other nickname");
    this->clients.push_back(Client(client));
}


void ClientRepository::removeClient(const std::string& nickname)
{
    for (std::list<Client>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if (nickname == it->getNickName())
        {
            clients.remove(*it);
            return;
        }
    }
}

const std::list<Client>& ClientRepository::getAllClient(void) const
{
    return this->clients;
}

