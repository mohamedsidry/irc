#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include "AUser.hpp"

class Client : public AUser
{
    public:
        Client(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        Client(const Client& copy);
        Client& operator=(const Client& other);
        virtual ~Client();
        void showInfo(void) const;
};



#endif // CLIENT_HPP

