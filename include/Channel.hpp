#pragma once

#include <iostream>
#include <string>
#include <cstddef>
#include "ChannelMode.hpp"

class Channel
{
    private:
        std::string name;
        std::string topic;
        size_t limits;
        std::string key;
        ChannelMode mode;

        void nameValidation(const std::string& name) const;
        void topicValidation(const std::string& name) const;

        Channel();
        Channel(const Channel& copy);
        Channel& operator=(const Channel&);

    public:
        Channel(const std::string& name, const std::string& topic);
        ~Channel();

        const std::string& getChannelName(void) const;
        const std::string& getChannelTopic(void) const;
        const std::string& getChannelKey(void) const;
        size_t getChannelLimits(void) const;
        const ChannelMode& getChannelMode(void) const;

        void setChannelName(const std::string& name);
        void setChannelTopic(const std::string& topic);
        void setChannelLimits(size_t size);

        static size_t NAME_LIMIT;
        static size_t TOPIC_LIMIT;
        static size_t MAX_SUBSCRIBERS;
        static std::string DEFAULT_KEY;
};

std::ostream& operator<<(std::ostream& os, const Channel& ref);
