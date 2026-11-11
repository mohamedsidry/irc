#ifndef MODERATORSSERVICE_HPP
#define MODERATORSSERVICE_HPP


#include <string>
class Moderator; // Forward declaration
class IUserManagement; // Forward declaration


class ModeratorsService
{
    private:
        IUserManagement& repository;    
        ModeratorsService(const ModeratorsService& copy); // delete
        ModeratorsService& operator=(const ModeratorsService& other); // delete
    public:
        ModeratorsService(IUserManagement& repo);

        void addModerator(Moderator *moderator);
        void removeModerator(const std::string& nickname);
        void renameModerator(const std::string& oldNickName, const std::string& newNickName);
        bool hasModerator(const std::string& nickname) const;
};


#endif // MODERATORSSERVICE_HPP

