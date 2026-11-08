#include "ClientService.hpp"
#include "ClientRepository.hpp"
#include "Client.hpp"
#include "IllegalArgumentException.hpp"

#include <iostream>

ClientService::ClientService(ClientRepository& repo):
repository(repo)
{}




ClientService::~ClientService(){}




Client* ClientService::findClient(const std::string& nickname) const
{
    return repository.getClient(nickname);
}



void ClientService::addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser)
{
    Client *client = NULL;
    try
    {
        client = new Client(nickname, username, hostname, hostuser);
        repository.addClient(client);
    }
    catch (const IllegalArgumentException& e)
    {
        std::cerr << e.what() << std::endl;
        delete client;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        delete client;
    }
}

void ClientService::removeClient(const std::string& nickname)
{
    repository.removeClient(nickname);
}


void ClientService::removeAll(void)
{
    repository.removeAll();
}

