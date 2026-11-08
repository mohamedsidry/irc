#pragma once

#include <string>

class Client; // Forward declaration
class SubscriptionRepository;

typedef Client Subscriber;

class SubscriptionService
{
    
    private:
        SubscriptionRepository& repository;
        SubscriptionService(const SubscriptionService& copy); // delete
        SubscriptionService& operator=(const SubscriptionService& other); // delete
    public:
        SubscriptionService(SubscriptionRepository& repository);
        ~SubscriptionService();
        Client* subscribe(Client* client);
        void unsubscribe(Client* client);
        void unsubscribe(const std::string& nickname);
        bool isSubscribed(Client* client) const;
        bool isSubscribed(const std::string& nickname) const;
        void unsubscribeAll(void);
};
