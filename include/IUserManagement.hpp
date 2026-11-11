#ifndef IUSERMANAGEMENT_HPP
#define IUSERMANAGEMENT_HPP

#include <string>
#include <cstddef>
#include "AUser.hpp"


class IUserManagement
{
    public:
        virtual ~IUserManagement(){};
        
        // Ownership transfers only on successful insertion.
        virtual void    add(AUser* user) = 0;
        virtual void    remove(const std::string& nickname) = 0;
        virtual bool    rename(const std::string& oldname, const std::string& newname) = 0;
        virtual bool    has(const std::string& nickname) const = 0;
        virtual std::size_t size(void) const = 0;
};



#endif // IUSERMANAGEMENT_HPP

