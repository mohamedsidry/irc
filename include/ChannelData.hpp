#ifndef CHANNELDATA_HPP
#define CHANNELDATA_HPP

#include <string>
#include <cstddef>
#include "ChannelMetaData.hpp"
#include "ChannelMode.hpp"
#include "SubscriptionRepository.hpp"
#include "OperatorsRepository.hpp"

class ChannelData
{
    private:
        ChannelMetaData         metaData;
        ChannelMode             mode;
        SubscriptionRepository  subscribers;
        OperatorsRepository     operators;
        ChannelData();
        ChannelData(const ChannelData& copy);
        ChannelData& operator=(const ChannelData& other);
    public:
        ChannelData(const std::string& metaName, const std::string& metaTopic, const std::string& metaKey, std::size_t metaLimit, const std::string& initialMode);
        ChannelMetaData&        getMetaData(void);
        ChannelMode&            getMode(void);
        SubscriptionRepository& getSubscribers(void);
        OperatorsRepository&    getOperators(void);

        const ChannelMetaData&        getMetaData(void)const ;
        const ChannelMode&            getMode(void)const ;
        const SubscriptionRepository& getSubscribers(void)const ;
        const OperatorsRepository&    getOperators(void)const ;
};

#endif // CHANNELDATA_HPP


