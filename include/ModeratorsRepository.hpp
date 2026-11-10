#ifndef MODERATORSREPOSITORY_HPP
#define MODERATORSREPOSITORY_HPP

#include <string>
#include <map>
#include <cstddef>
#include "IUsersManagment.hpp"
#include "Moderator.hpp"


class ModeratorsRepository : public IUsersManagment
{
    private:
        std::map<std::string, Moderator *> moderators;
    public:
        typedef std::map<std::string, Moderator *>::const_iterator const_iterator;
        typedef std::map<std::string, Moderator *>::iterator iterator;
        ModeratorsRepository();
        ModeratorsRepository(const ModeratorsRepository&);
        ModeratorsRepository& operator=(const ModeratorsRepository&);
        ~ModeratorsRepository();
        void    add(AUser* user);
        void    remove(const std::string& nickname);
        void    rename(const std::string& oldname, const std::string& newname);
        bool    has(const std::string& nickname) const;
        std::size_t size(void) const;
};

#endif  // MODERATORSREPOSITORY_HPP
