#include "../../../include/ChannelData.hpp"


ChannelData::ChannelData(const std::string& metaName, const std::string& metaTopic, const std::string& metaKey, size_t metaLimit, const std::string& mode):
metaData(metaName, metaTopic, metaKey, metaLimit),
mode(mode),
subscribers(),
operators()
{}


ChannelData::ChannelData(const ChannelData& copy):
metaData(copy.metaData),
mode(copy.mode),
subscribers(copy.subscribers),
operators(copy.operators)
{}



ChannelData& ChannelData::operator=(const ChannelData& other)
{
    if (this != &other)
    {
        this->metaData = other.metaData;
        this->mode = other.mode;
        this->subscribers = other.subscribers;
        this->operators = other.operators;
    }
    return (*this);
}



ChannelData::~ChannelData(){}




ChannelMetaData&        ChannelData::getMetaData(void){return metaData;}
ChannelMode&            ChannelData::getMode(void){return mode;}
SubscriptionRepository& ChannelData::getSubscribers(void){return subscribers;}
OperatorsRepository&    ChannelData::getOperators(void){return operators;}

const ChannelMetaData&        ChannelData::getMetaData(void)const {return metaData;}
const ChannelMode&            ChannelData::getMode(void)const {return mode;}
const SubscriptionRepository& ChannelData::getSubscribers(void)const {return subscribers;}
const OperatorsRepository&    ChannelData::getOperators(void)const {return operators;}
