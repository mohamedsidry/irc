#include "OperateService.hpp"
#include "OperatorsRepository.hpp"
#include "Client.hpp"
#include "IllegalArgumentException.hpp"



OperateService::OperateService(OperatorsRepository& repo):
repository(repo)
{}



OperateService::~OperateService(){}


Client* OperateService::startOperating(Client* client)
{
    if (client && !isOperator(client))
        return repository.addClient(client);
    return NULL;
}

void OperateService::stopOperating(const std::string& nickname)
{
    if (repository.hasClient(nickname))
        repository.removeClient(nickname);
}


void OperateService::stopOperating(Client* client)
{
    if (client && isOperator(client))
        stopOperating(client->getNickName());
}


bool OperateService::isOperator(Client* client) const
{
    if (!client)
        return false;
    return repository.hasClient(client->getNickName());
}

bool OperateService::isOperator(const std::string& nickname) const
{
    return repository.hasClient(nickname);
}


void OperateService::stopAllOperators(void)
{
    repository.removeAll();
}

