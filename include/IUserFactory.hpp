#ifndef IUSERFACTORY_HPP
#define IUSERFACTORY_HPP

#include <string>
#include "AUser.hpp"

class IUserFactory
{
    public:
        static AUser* createUser(
            const std::string& type,
            const std::string& nickname,
            const std::string& username,
            const std::string& hostname,
            const std::string& hostuser);
};




#endif // IUSERFACTORY_HPP

