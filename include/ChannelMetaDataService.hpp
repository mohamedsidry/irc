#pragma once

#include <string>

class ChannelMetaData;

class ChannelMetaDataService
{
    private:
        ChannelMetaData& data;
        void validateName(const std::string& name) const;
        void validateTopic(const std::string& topic) const;
    public:
        ChannelMetaDataService(ChannelMetaData& data);
        ~ChannelMetaDataService();
        void changeName(const std::string& name);
        void changeTopic(const std::string& topic);
        void changeKey(const std::string& key);
        void changeLimit(size_t limit);

        const std::string& getChannelName(void) const;
        const std::string& getChannelTopic(void) const;
        const std::string& getChannelKey(void) const;
        size_t getChannelLimit(void)const;
};

