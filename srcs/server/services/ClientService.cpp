#include "../../../include/ClientService.hpp"






ClientService::ClientService(ClientRepository& repo):
repository(repo)
{}




ClientService::~ClientService(){}




const Client& ClientService::findClient(const std::string& nickname) const
{
    return this->repository.getClient(nickname);
}



void ClientService::addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser)
{
    Client *client = NULL;
    try
    {
        client = new Client(nickname, username, hostname, hostuser);
        this->repository.addClient(client);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const IllegalArgumentException& e)
    {
        std::cerr << e.what() << std::endl;
        delete client;
    }
}

void ClientService::removeClient(const std::string& nickname)
{
    repository.removeClient(nickname);
}


