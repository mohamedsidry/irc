#pragma once


#include "ISearchableClient.hpp"
#include "IClientManagment.hpp"

class ClientRepository : public ISearchableClient, public IClientManagment
{
    private:
        std::list<Client> clients;
    public:

        ClientRepository();
        ClientRepository(const ClientRepository& copy);
        ClientRepository& operator=(const ClientRepository& other);
        ~ClientRepository();

        bool hasClient(const std::string& nickname) const;
        const Client& getClient(const std::string& nickname) const;
        void addClient(const Client& client);
        void removeClient(const std::string& nickname);
        const std::list<Client>& getAllClient(void) const;
};

