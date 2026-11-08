#pragma once

#include <string>
#include "ChannelMode.hpp"

class ChannelModeService
{
    private:
        ChannelMode mode;
        void validateOption(unsigned char c) const;
        void validateMode(const std::string& option) const;
        
    public:
        ChannelModeService();
        ChannelModeService(const ChannelModeService& copy);
        ChannelModeService& operator=(const ChannelModeService& other);
        ~ChannelModeService();

        const   std::string& getChannelModes(void) const;
        void    updateChannelMode(const std::string& option);
        void    addMode(unsigned char option);
        void    removeMode(unsigned char option);
        bool    hasMode(unsigned char option) const;

        static std::string SUPPORTED_OPTIONS;
        static std::string DEFAULT_MODE;

};

