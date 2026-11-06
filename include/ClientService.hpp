#pragma once

#include "main.hpp"


class ClientRepository;

class ClientService
{
    private:
        ClientRepository& repository;    
        ClientService();
    public:
        ClientService(ClientRepository& repository);
        ClientService(const ClientService& copy);
        ClientService& operator=(const ClientService& other);
        ~ClientService();

        const Client& findClient(const std::string& nickname) const;
        void addClient(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        void removeClient(const std::string& nickname);
};
