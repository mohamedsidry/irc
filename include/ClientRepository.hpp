#pragma once

#include <map>
#include <string>

#include "ISearchableClient.hpp"
#include "IClientManagment.hpp"
class Client; // Forward declaration

class ClientRepository : public ISearchableClient, public IClientManagment
{
    private:
        std::map<std::string, Client*> clients;
    public:

        ClientRepository();
        ClientRepository(const ClientRepository& copy);
        ClientRepository& operator=(const ClientRepository& other);
        ~ClientRepository();

        bool hasClient(const std::string& nickname) const;
        void removeClient(const std::string& nickname);
        Client* getClient(const std::string& nickname);
        Client* addClient(Client* client);
        const std::map<std::string, Client*>& getAllClient(void) const;
};

