#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <string>
#include "AUser.hpp"

class Subscriber : public AUser
{
    public:
        Subscriber(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        Subscriber(const Subscriber& copy);
        Subscriber& operator=(const Subscriber& other);
        ~Subscriber();
        void showInfo(void) const;
};



#endif // SUBSCRIBER_HPP

