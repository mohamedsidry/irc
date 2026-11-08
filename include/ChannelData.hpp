#pragma once

#include <string>
#include <iostream>


class ChannelData
{
    private:
        std::string name;
        std::string topic;
        std::string key;
        size_t limit;
        ChannelData();
    public:
        ChannelData(const std::string& name, const std::string& topic, const std::string& key, size_t limit);
        ChannelData(const ChannelData& copy);
        ChannelData& operator=(const ChannelData& other);
        ~ChannelData();

        const std::string& getChannelName(void) const;
        const std::string& getChannelTopic(void) const;
        const std::string& getChannelKey(void) const;
        size_t getChannelLimit(void) const;
        void setChannelName(const std::string& name);
        void setChannelTopic(const std::string& topic);
        void setChannelKey(const std::string& key);
        void setChannelLimit(size_t size);
};


std::ostream& operator<<(std::ostream&, const ChannelData& ref);

