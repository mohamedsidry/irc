#pragma once

#include "main.hpp"

class ChannelMode
{
    private:
        std::string flags;
        void modeValidation(const std::string& options) const;
        bool validOption(const std::string& option) const;

    public:
        static std::string SUPPORTED_MODES;
        static std::string DEFAULT_MODES;
        ChannelMode();
        ChannelMode(const std::string& mode);
        ChannelMode(const ChannelMode& copy);
        ChannelMode& operator=(const ChannelMode& other);
        ~ChannelMode();

        const std::string& getModes() const;
        void setMode(const std::string& mode);
        void updateMode(const std::string& option);
        bool hasOption(unsigned char option) const;
};

