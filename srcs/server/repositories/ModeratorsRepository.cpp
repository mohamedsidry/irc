#include "Moderator.hpp"
#include "ModeratorsRepository.hpp"
#include "IllegalArgumentException.hpp"

ModeratorsRepository::ModeratorsRepository()
{}

ModeratorsRepository::ModeratorsRepository(const ModeratorsRepository& copy)
{
    for (ModeratorsRepository::const_iterator it = copy.moderators.begin(); it != copy.moderators.end(); ++it)
        moderators[it->first] = it->second;
}

ModeratorsRepository& ModeratorsRepository::operator=(const ModeratorsRepository& other)
{
    if (this != &other)
    {
        moderators.clear();
        for (ModeratorsRepository::const_iterator it = other.moderators.begin(); it != other.moderators.end(); ++it)
            moderators[it->first] = it->second;
    }
    return *this;
}

ModeratorsRepository::~ModeratorsRepository(){}

void ModeratorsRepository::add(AUser* user)
{
    Moderator *moderator = NULL;
    if (!user)
        return;
    moderator = dynamic_cast<Moderator*>(user);
    if (!moderator)
        throw IllegalArgumentException("Adding user to moderatos which is not of type Moderator");
    moderators.insert(std::make_pair(moderator->getNickName(), moderator));
}


void ModeratorsRepository::remove(const std::string& nickname)
{
    ModeratorsRepository::iterator it = moderators.find(nickname);

    if (it != moderators.end())
        moderators.erase(it);
}


bool ModeratorsRepository::rename(const std::string& oldNickName, const std::string& newNickName)
{
    ModeratorsRepository::iterator target = moderators.find(oldNickName);
    if (oldNickName == newNickName)
        return true;
    if (target == moderators.end())
        return false;
    Moderator* moderator = target->second;
    moderators.insert(std::make_pair(newNickName, moderator));
    moderator->setNickName(newNickName);
    moderators.erase(target);
    return true;
}

bool ModeratorsRepository::has(const std::string& nickname) const
{
    return moderators.find(nickname) != moderators.end();
}


std::size_t ModeratorsRepository::size(void) const
{
    return moderators.size();
}

