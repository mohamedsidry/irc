#pragma once

#include "main.hpp"

/**
 * @brief Represents a client
 * 
 * @details represents a client 
 * @param nickName : client unique Identifier with max of 9 characters .
 * @param userName : client username .
 * @param hostName : client machine name .
 * @param hostUser : client host machine user . 
 *
 * @note nickname has to be unique . 
 * @throws illegalArgumentException if invalid params .

 */

class Client
{
    private:
        std::string nickName;
        std::string userName;
        std::string hostName;
        std::string hostUser;
        Client(const Client& copy);
        Client();
    public:
        Client(const std::string& nn, const std::string& un, const std::string& hn, const std::string& hu);
        Client& operator=(const Client& other);
        ~Client();

        const std::string& getNickName(void) const;
        const std::string& getUserName(void) const;
        const std::string& getHostName(void) const;
        const std::string& getHostUser(void) const;

        bool operator==(const Client& other) const;
        bool operator!=(const Client& other) const;
};

std::ostream& operator<<(std::ostream& os, const Client& client);


