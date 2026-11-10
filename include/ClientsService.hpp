#ifndef CLIENTSERVICE_HPP
#define CLIENTSERVICE_HPP

#include <string>

class Client; // Forward declaration
class ClientsRepository; // Forward declaration

class ClientsService
{
    private:
        ClientsRepository& repository;    
        ClientsService(const ClientsService& copy); // delete
        ClientsService& operator=(const ClientsService& other); // delete
    public:
        ClientsService(ClientsRepository& repository);
        bool hasClient(const std::string& nickname) const;
        void addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        void removeClient(const std::string& nickname);
        void renameClient(const std::string& oldNickName, const std::string& newNickName);
};


#endif // CLIENTSERVICE_HPP

