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
    this->repository.addClient(Client(nickname, username, hostname, hostuser));
}


void ClientService::removeClient(const std::string& nickname)
{
    repository.removeClient(nickname);
}


