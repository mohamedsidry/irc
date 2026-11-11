#include "ClientsRepository.hpp"
#include "Utils.hpp"
#include "Config.hpp"
#include "IllegalArgumentException.hpp"
#include "Client.hpp"


ClientsRepository::ClientsRepository()
{}


ClientsRepository::~ClientsRepository()
{
    for (iterator it = clients.begin(); it != clients.end(); ++it)
        delete it->second;
}

/**
 * @brief Adds a user to the repository.
 *
 * @param user Pointer to the user.
 * @note Ownership transfers to the repository
 *       only if insertion succeeds.
 */
void ClientsRepository::add(AUser* user)
{
    Client *client = NULL;
    if (!user)
        throw IllegalArgumentException("Null client");
    client = dynamic_cast<Client*>(user);
    if (!client)
        throw IllegalArgumentException("Adding user to clients which is not of type Client");
    clients.insert(std::make_pair(client->getNickName(), client));
}


void ClientsRepository::remove(const std::string& nickname)
{
    iterator it = clients.find(nickname);
    if (it == clients.end())
        return ;
    delete it->second;
    clients.erase(it);
}


bool ClientsRepository::rename( const std::string& oldNickName, const std::string& newNickName)
{
    iterator target = clients.find(oldNickName);
    if (oldNickName == newNickName)
        return true;
    if (target == clients.end())
        return false;
    Client* client = target->second;
    clients.insert(std::make_pair(newNickName, client));
    client->setNickName(newNickName);
    clients.erase(target);
    return true;
}

bool ClientsRepository::has(const std::string& nickname) const
{
    return clients.find(nickname) != clients.end();
}



std::size_t ClientsRepository::size(void) const
{
    return clients.size();
}

