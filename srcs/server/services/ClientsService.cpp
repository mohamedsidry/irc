#include "ClientsService.hpp"
#include "ClientsRepository.hpp"
#include "IllegalArgumentException.hpp"
#include "Config.hpp"
#include "Utils.hpp"

ClientsService::ClientsService(ClientsRepository& repo):
repository(repo)
{}


void ClientsService::addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser)
{
    if (nickname.empty() || Utils::isAllWhitespace(nickname))
        throw IllegalArgumentException("Empty nickname");
    if (nickname.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + nickname);
    if (repository.has(nickname))
        throw IllegalArgumentException(nickname + " Already in use try an other nickname");
    repository.add(repository.create(nickname, username, hostname, hostuser));
}

void ClientsService::removeClient(const std::string& nickname)
{
    if (repository.has(nickname))
        repository.remove(nickname);
    else
        throw IllegalArgumentException("No Client known by" + nickname);
}


void ClientsService::renameClient(const std::string& oldNickName, const std::string& newNickName)
{
    if (newNickName.empty() || Utils::isAllWhitespace(newNickName))
        throw IllegalArgumentException("Empty nickname");
    if (newNickName.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + newNickName);
    if (!repository.has(oldNickName))
        throw IllegalArgumentException("No client known by" + oldNickName);
    if (repository.has(newNickName))
        throw IllegalArgumentException(oldNickName + " Already in use try an other nickname");
    repository.rename(oldNickName, newNickName);
}

bool ClientsService::hasClient(const std::string& nickname) const
{
    return repository.has(nickname);
}
