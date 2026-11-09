#ifndef ICLIENTMANAGMENT_HPP
#define ICLIENTMANAGMENT_HPP

#include <string>

class Client; // Forward declaration

class IClientManagment
{
    public:
        virtual ~IClientManagment(){}
        virtual Client* addClient(Client* client) = 0;
        virtual void removeClient(const std::string& nickname) = 0;
        virtual void removeAll(void) = 0;
};

#endif // ICLIENTMANAGMENT_HPP

