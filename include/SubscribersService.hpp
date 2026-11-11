#ifndef SUBSCRIBERSSERVICE_HPP
#define SUBSCRIBERSSERVICE_HPP


#include <string>
class Subscriber; // Forward declaration
class IUserManagement; // Forward declaration

class SubscribersService
{
    private:
        IUserManagement& repository;    
        SubscribersService(const SubscribersService& copy); // delete
        SubscribersService& operator=(const SubscribersService& other); // delete
    public:
        SubscribersService(IUserManagement& repo);

        void addSubscriber(Subscriber *Subscriber);
        void removeSubscriber(const std::string& nickname);
        void renameSubscriber(const std::string& oldNickName, const std::string& newNickName);
        bool hasSubscriber(const std::string& nickname) const;
};


#endif // SUBSCRIBERSSERVICE_HPP
