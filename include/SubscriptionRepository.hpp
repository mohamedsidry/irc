#pragma once


#include <map>
#include <string>
#include "ISearchableClient.hpp"
#include "IClientManagment.hpp"

class Client; // Forward declaration

class SubscriptionRepository : public ISearchableClient, public IClientManagment
{
    private:
        std::map<std::string, Client*> clients;
    public:

        SubscriptionRepository();
        SubscriptionRepository(const SubscriptionRepository& copy);
        SubscriptionRepository& operator=(const SubscriptionRepository& other);
        ~SubscriptionRepository();

        bool hasClient(const std::string& nickname) const;
        void removeClient(const std::string& nickname);
        void removeAll(void);
        Client* getClient(const std::string& nickname);
        Client* addClient(Client* client);
        const std::map<std::string, Client*>& getAllClient(void) const;
};

