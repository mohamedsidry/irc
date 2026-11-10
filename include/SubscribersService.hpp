#ifndef SUBSCRIBERSSERVICE_HPP
#define SUBSCRIBERSSERVICE_HPP


#include <string>
class Subscriber; // Forward declaration
class SubscribersRepository; // Forward declaration


class SubscribersService
{
    private:
        SubscribersRepository& repository;    
        SubscribersService(const SubscribersService& copy); // delete
        SubscribersService& operator=(const SubscribersService& other); // delete
    public:
        SubscribersService(SubscribersRepository& repo);

        void addSubscriber(Subscriber *Subscriber);
        void removeSubscriber(const std::string& nickname);
        void renameSubscriber(const std::string& oldNickName, const std::string& newNickName);
        bool hasSubscriber(const std::string& nickname) const;
};


#endif // SUBSCRIBERSSERVICE_HPP
