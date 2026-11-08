#pragma once

#include <string>
#include "ChannelMode.hpp"

class ChannelModeService
{
    private:
        ChannelMode mode;
        bool validOption(const std::string& option) const;
        
    public:
        ChannelModeService();
        ChannelModeService(const ChannelModeService& copy);
        ChannelModeService& operator=(const ChannelModeService& other);
        ~ChannelModeService();

        const   std::string& getChannelModes(void) const;
        void    updateChannelMode(const std::string& option);

        static std::string SUPPORTED_OPTIONS;
        static std::string DEFAULT_MODE;

};

