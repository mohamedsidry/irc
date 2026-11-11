#ifndef CLIENTSERVICE_HPP
#define CLIENTSERVICE_HPP

#include <string>

class Client; // Forward declaration
class IUserManagement; // Forward declaration

class ClientsService
{
    private:
        IUserManagement& repository;    
        ClientsService(const ClientsService& copy); // delete
        ClientsService& operator=(const ClientsService& other); // delete
    public:
        ClientsService(IUserManagement& repository);
        bool hasClient(const std::string& nickname) const;
        void addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        void removeClient(const std::string& nickname);
        void renameClient(const std::string& oldNickName, const std::string& newNickName);
};


#endif // CLIENTSERVICE_HPP

