#include "../../../include/ClientRepository.hpp"



ClientRepository::ClientRepository(){}



ClientRepository::ClientRepository(const ClientRepository& copy):
clients(copy.clients)
{}





ClientRepository& ClientRepository::operator=(const ClientRepository& other)
{
    if (this != &other)
        this->clients = other.clients;
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
    std::pair<std::map<std::string, Client>::iterator, bool> result;

    result = clients.insert(
        std::make_pair(client.getNickName(), client)
    );

    if (result.second == false)
        throw IllegalArgumentException(
            client.getNickName() + " already used"
        );
}


void ClientRepository::removeClient(const std::string& nickname)
{
    clients.erase(nickname);
}

const std::map<std::string, Client>& ClientRepository::getAllClient(void) const
{
    return this->clients;
}

