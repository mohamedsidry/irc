#pragma once

#include <string>
#include "IllegalArgumentException.hpp"
#include "Utils.hpp"

class ChannelMode
{
    private:
        std::string flags;
        ChannelMode();

    public:
        ChannelMode(const std::string& flags);
        ChannelMode(const ChannelMode& copy);
        ChannelMode& operator=(const ChannelMode& other);
        ~ChannelMode();

        const std::string& getFlags() const;
        void addFlag(unsigned char c);
        void removeFlag(unsigned char c);
        bool hasFlag(unsigned char option) const;
};

