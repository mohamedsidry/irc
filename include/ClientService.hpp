#pragma once

#include <string>

class Client; // Forward declaration
class ClientRepository; // Forward declaration

class ClientService
{
    private:
        ClientRepository& repository;    
        ClientService(const ClientService& copy); // delete
        ClientService& operator=(const ClientService& other); // delete
    public:
        ClientService(ClientRepository& repository);
        ~ClientService();
        Client* findClient(const std::string& nickname) const;
        void addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        void removeClient(const std::string& nickname);
        void removeAll(void);
};
