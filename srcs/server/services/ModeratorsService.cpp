#include "Moderator.hpp"
#include "ModeratorsService.hpp"
#include "IUserManagement.hpp"
#include "IllegalArgumentException.hpp"
#include "Utils.hpp"
#include "Config.hpp"

ModeratorsService::ModeratorsService(IUserManagement& repo):
repository(repo)
{}



void ModeratorsService::addModerator(Moderator *moderator)
{
    if (!moderator)
        return;
    repository.add(moderator);
}

void ModeratorsService::removeModerator(const std::string& nickname)
{
    if (repository.has(nickname))
        repository.remove(nickname);
    else
        throw IllegalArgumentException("No moderator known by " + nickname);
}


void ModeratorsService::renameModerator(const std::string& oldNickName, const std::string& newNickName)
{
    if (newNickName.empty() || Utils::isAllWhitespace(newNickName))
        throw IllegalArgumentException("Empty nickname");
    if (newNickName.size() > Config::USER_NICKNAME_LIMIT)
        throw IllegalArgumentException("Too Long nickname " + newNickName);
    if (!repository.has(oldNickName))
        throw IllegalArgumentException("No moderator known by " + oldNickName);
    if (repository.has(newNickName))
        throw IllegalArgumentException(newNickName + " Already in use try an other nickname");
    repository.rename(oldNickName, newNickName);
}


bool ModeratorsService::hasModerator(const std::string& nickname) const
{
    return repository.has(nickname);
}
