#ifndef CHANNEL_HPP
#define CHANNEL_HPP


#include <string>
#include <cstddef>
#include <iosfwd>

#include "ChannelData.hpp"
#include "ChannelServices.hpp"

class Channel
{
    private:
        ChannelData     data;
        ChannelServices services;
        Channel();
        Channel(const Channel&);
        Channel& operator=(const Channel&);
    public:
        static const size_t NAME_LIMIT = 200;
        static const size_t TOPIC_LIMIT = 256;
        static const size_t DEFAULT_SUBSCRIBERS_LIMIT = 1024;

        static const std::string DEFAULT_KEY;
        static const std::string DEFAULT_MODE;
        static const std::string SUPPORTED_MODES;
 
        Channel(const std::string& name, const std::string& topic);
        ~Channel();
        
        ChannelServices& getServices(void);
        const ChannelServices& getServices(void) const;
        
};

std::ostream& operator<<(std::ostream& os, const Channel& ref);

#endif // CHANNEL_HPP

