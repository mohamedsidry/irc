#ifndef SUBSCRIPTIONSERVICE_HPP
#define SUBSCRIPTIONSERVICE_HPP

#include <string>

class Client; // Forward declaration
class SubscriptionRepository;

typedef Client Subscriber;

class SubscriptionService
{
    
    private:
        SubscriptionRepository& repository;
        SubscriptionService(const SubscriptionService& copy); 
        SubscriptionService& operator=(const SubscriptionService& other);
    public:
        SubscriptionService(SubscriptionRepository& repository);
        Client* subscribe(Client* client);
        void unsubscribe(Client* client);
        void unsubscribe(const std::string& nickname);
        bool isSubscribed(Client* client) const;
        bool isSubscribed(const std::string& nickname) const;
        void unsubscribeAll(void);
};

#endif // SUBSCRIPTIONSERVICE_HPP

