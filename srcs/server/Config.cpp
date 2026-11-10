#include "Config.hpp"

const std::string Config::CHANNEL_DEFAULT_KEY = "";
const std::string Config::CHANNEL_DEFAULT_MODE = "t";
const std::string Config::CHANNEL_SUPPORTED_MODES = "itkol";



Config::Config(const std::string& port, const std::string& password):
port(port),
password(password)
{}

Config::Config(const Config& copy):
port(copy.port),
password(copy.password)
{}



Config& Config::operator=(const Config& other)
{
    if (this != &other)
    {
        this->port = other.port;
        this->password = other.password;
    }
    return (*this);
}


const std::string& Config::getPort(void)const {return port;}
const std::string& Config::getPassword(void) const {return password;}

