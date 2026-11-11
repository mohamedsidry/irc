#include "ClientsService.hpp"
#include "IUserManagement.hpp"
#include "IllegalArgumentException.hpp"
#include "Config.hpp"
#include "Utils.hpp"
#include "IUserFactory.hpp"

ClientsService::ClientsService(IUserManagement& repo):
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
    AUser * client = IUserFactory::createUser("Client", nickname, username, hostname, hostuser);

    try
    {repository.add(client);}
    catch(const std::exception& e)
    {
        delete client;
        throw IllegalArgumentException("Could not add client " + nickname);
    }
}

void ClientsService::removeClient(const std::string& nickname)
{
    repository.remove(nickname);
}


void ClientsService::renameClient(const std::string& oldNickName, const std::string& newNickName)
{
    if (oldNickName == newNickName)
        return;
    if (newNickName.empty() || Utils::isAllWhitespace(newNickName))
        throw IllegalArgumentException("Empty nickname");
    if (newNickName.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + newNickName);
    if (!repository.has(oldNickName))
        throw IllegalArgumentException("No client known by" + oldNickName);
    if (repository.has(newNickName))
        throw IllegalArgumentException(newNickName + " Already in use try an other nickname");
    repository.rename(oldNickName, newNickName);
}

bool ClientsService::hasClient(const std::string& nickname) const
{
    return repository.has(nickname);
}
