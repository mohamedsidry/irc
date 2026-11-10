#ifndef MODERATOR_HPP
#define MODERATOR_HPP

#include <string>
#include "AUser.hpp"

class Moderator : public AUser
{
    public:
        Moderator(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        Moderator(const Moderator& copy);
        Moderator& operator=(const Moderator& other);
        ~Moderator();
        void showInfo(void) const;
};



#endif // MODERATOR_HPP

