#ifndef SUBSCRIBERSREPOSITORY_HPP
#define SUBSCRIBERSREPOSITORY_HPP

#include <string>
#include <map>
#include "IUsersManagment.hpp"
#include "Subscriber.hpp"


class SubscribersRepository : public IUsersManagment
{
    private:
        std::map<std::string, Subscriber *> subscribers;
    public:
        typedef std::map<std::string, Subscriber *>::const_iterator const_iterator;
        typedef std::map<std::string, Subscriber *>::iterator iterator;
        SubscribersRepository();
        SubscribersRepository(const SubscribersRepository&);
        SubscribersRepository& operator=(const SubscribersRepository&);
        ~SubscribersRepository();
        void    add(AUser* user);
        void    remove(const std::string& nickname);
        void    rename(const std::string& oldname, const std::string& newname);
        bool    has(const std::string& nickname) const;
        std::size_t size(void) const;
};

#endif  // SUBSCRIBERSREPOSITORY_HPP
