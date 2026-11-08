#include "SubscriptionService.hpp"
#include "SubscriptionRepository.hpp"
#include "Client.hpp"
#include "IllegalArgumentException.hpp"



SubscriptionService::SubscriptionService(SubscriptionRepository& repo):
repository(repo)
{}



SubscriptionService::~SubscriptionService(){}


Client* SubscriptionService::subscribe(Client* client)
{
    if (client && !isSubscribed(client))
        return repository.addClient(client);
    return NULL;
}

void SubscriptionService::unsubscribe(const std::string& nickname)
{
    if (repository.hasClient(nickname))
        repository.removeClient(nickname);
}


void SubscriptionService::unsubscribe(Client* client)
{
    if (client && isSubscribed(client))
        unsubscribe(client->getNickName());
}


bool SubscriptionService::isSubscribed(Client* client) const
{
    if (!client)
        return false;
    return repository.hasClient(client->getNickName());
}

bool SubscriptionService::isSubscribed(const std::string& nickname) const
{
    return repository.hasClient(nickname);
}


void SubscriptionService::unsubscribeAll(void)
{
    repository.removeAll();
}

