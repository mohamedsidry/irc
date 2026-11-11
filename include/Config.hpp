#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <cstddef>

class Config
{
    private:
        std::string port;
        std::string password;
        
    public:
        static const std::size_t USER_NICKNAME_LIMIT = 9;
        static const std::size_t CHANNEL_TOPIC_LIMIT = 256;
        static const std::size_t DEFAULT_SUBSCRIBERS_LIMIT = 1024;
        static const std::string CHANNEL_DEFAULT_KEY;
        static const std::string CHANNEL_DEFAULT_MODE;
        static const std::string CHANNEL_SUPPORTED_MODES;

        Config(const std::string& port, const std::string& password);
        Config(const Config&);
        Config& operator=(const Config&);
        ~Config();

        const std::string& getPort(void)const;
        const std::string& getPassword(void) const;
};

#endif // CONFIG_HPP

