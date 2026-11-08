#pragma once

#include <string>

class ChannelData;

class ChannelDataService
{
    private:
        ChannelData& data;
        void validateName(const std::string& name) const;
        void validateTopic(const std::string& topic) const;
    public:
        ChannelDataService(ChannelData& data);
        ~ChannelDataService();
        void changeName(const std::string& name);
        void changeTopic(const std::string& topic);
        void changeKey(const std::string& key);
        void changeLimit(size_t limit);

        const std::string& getChannelName(void) const;
        const std::string& getChannelTopic(void) const;
        const std::string& getChannelKey(void) const;
        size_t getChannelLimit(void)const;
};

