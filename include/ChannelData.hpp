#ifndef CHANNELDATA_HPP
#define CHANNELDATA_HPP

#include <string>
#include <cstddef>
#include "ChannelMetaData.hpp"
#include "ChannelMode.hpp"
#include "SubscribersRepository.hpp"
#include "ModeratorsRepository.hpp"

class ChannelData
{
    private:
        ChannelMetaData         metaData;
        ChannelMode             mode;
        SubscribersRepository  subscribers;
        ModeratorsRepository     moderators;
        ChannelData();
        ChannelData(const ChannelData& copy);
        ChannelData& operator=(const ChannelData& other);
    public:
        ChannelData(const std::string& metaName, const std::string& metaTopic, const std::string& metaKey, std::size_t metaLimit, const std::string& initialMode);
        ChannelMetaData&        getMetaData(void);
        ChannelMode&            getMode(void);
        SubscribersRepository& getSubscribers(void);
        //ModeratorsRepository&    getOperators(void);

        const ChannelMetaData&        getMetaData(void)const ;
        const ChannelMode&            getMode(void)const ;
        const SubscribersRepository& getSubscribers(void)const ;
        //const ModeratorsRepository&    getOperators(void)const ;
};

#endif // CHANNELDATA_HPP


