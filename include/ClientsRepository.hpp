#ifndef CLIENTSREPOSITORY_HPP
#define CLIENTSREPOSITORY_HPP

#include <map>
#include <string>
#include "IUserManagement.hpp"

class Client; // Forward declaration

class ClientsRepository : public IUserManagement
{
    private:
        std::map<std::string, Client *> clients;
        ClientsRepository(const ClientsRepository&);
        ClientsRepository& operator=(const ClientsRepository&);
    public:
        typedef std::map<std::string, Client*>::const_iterator const_iterator;
        typedef std::map<std::string, Client*>::iterator iterator;
        ClientsRepository();
        ~ClientsRepository();
        AUser*  create(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser) const;
        void    add(AUser* user);
        void    remove(const std::string& nickname);
        bool    rename(const std::string& oldname, const std::string& newname);
        bool    has(const std::string& nickname) const;
        std::size_t size(void) const;
};


#endif // CLIENTSREPOSITORY_HPP
