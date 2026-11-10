#ifndef IUSERMANAGMENT_HPP
#define IUSERMANAGMENT_HPP

#include <cstddef>

class AUser;

class IUsersManagment
{
    public:
        virtual ~IUsersManagment(){};
        virtual void    add(AUser* user) = 0;
        virtual void    remove(const std::string& nickname) = 0;
        virtual void    rename(const std::string& oldname, const std::string& newname) = 0;
        virtual bool    has(const std::string& nickname) const = 0;
        virtual std::size_t size(void) const = 0;
};



#endif // IUSERMANAGMENT_HPP

