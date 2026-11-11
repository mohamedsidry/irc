#ifndef AUser_HPP
#define AUser_HPP

#include <string>
#include <iosfwd>


/**
 * @brief Abstract class represents a user
 * 
 * @details represents a user that has :
 * @param nickName : user unique Identifier with max of 9 characters .
 * @param userName : user AUsername .
 * @param hostName : user machine name .
 * @param hostAUser : user host machine user . 
 *
 * @note nickname has to be unique . 
 *
 */

class AUser
{
    private:
        std::string nickName;
        std::string userName;
        std::string hostName;
        std::string hostUser;
    public:
        AUser(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        AUser(const AUser& copy);
        AUser& operator=(const AUser& other);
        virtual ~AUser();
        virtual void showInfo(void) const = 0;

        const std::string& getNickName(void) const;
        const std::string& getUserName(void) const;
        const std::string& getHostName(void) const;
        const std::string& getHostUser(void) const;

        void setNickName(const std::string& nickname);
        void setUserName(const std::string& username);
        void setHostName(const std::string& hostname);
        void setHostUser(const std::string& hostuser); 

        bool operator==(const AUser& other) const;
        bool operator!=(const AUser& other) const;
};


std::ostream& operator<<(std::ostream& os, const AUser& user);

#endif // AUser_HPP

