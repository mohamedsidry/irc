#include "ClientsRepository.hpp"
#include "Utils.hpp"
#include "Config.hpp"
#include "IllegalArgumentException.hpp"
#include "Client.hpp"


ClientsRepository::ClientsRepository()
{}

ClientsRepository::ClientsRepository(const ClientsRepository& copy)
{
    for (ClientsRepository::const_iterator it = copy.clients.begin(); it != copy.clients.end(); ++it)
    {
        clients[it->first] = new Client(*it->second);
    }
}

ClientsRepository& ClientsRepository::operator=(const ClientsRepository& other)
{
    if (this != &other)
    {
        for (ClientsRepository::iterator it = clients.begin(); it != clients.end(); ++it)
            delete it->second;
        clients.clear();
        for (ClientsRepository::const_iterator it = other.clients.begin(); it != other.clients.end(); ++it)
            clients[it->first] = new Client(*it->second);
    }
    return *this;
}


ClientsRepository::~ClientsRepository()
{
    for (ClientsRepository::iterator it = clients.begin(); it != clients.end(); ++it)
        delete it->second;
}


AUser* ClientsRepository::create(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser) const
{
    return new Client(nickname, username, hostname, hostuser);
}


void ClientsRepository::add(AUser* user)
{
    Client *client = NULL;
    if (!user)
        return;
    client = dynamic_cast<Client*>(user);
    if (!client)
        throw IllegalArgumentException("Adding user to clients which is not of type Client");
    clients.insert(std::make_pair(client->getNickName(), client));
}


void ClientsRepository::remove(const std::string& nickname)
{
    ClientsRepository::iterator it = clients.find(nickname);

    if (it != clients.end())
    {
        delete it->second;
        clients.erase(it);
    }
}


void ClientsRepository::rename(
    const std::string& oldNickName,
    const std::string& newNickName)
{
    ClientsRepository::iterator target = clients.find(oldNickName);

    if (target != clients.end())
    {
        Client* client = target->second;

        clients.erase(target);

        client->setNickName(newNickName);

        clients.insert(std::make_pair(newNickName, client));
    }
}

bool ClientsRepository::has(const std::string& nickname) const
{
    return clients.find(nickname) != clients.end();
}



std::size_t ClientsRepository::size(void) const
{
    return clients.size();
}

