#include "ChannelData.hpp"


ChannelData::ChannelData(const std::string& metaName, const std::string& metaTopic, const std::string& metaKey, std::size_t metaLimit, const std::string& mode):
metaData(metaName, metaTopic, metaKey, metaLimit),
mode(mode),
subscribers(),
operators()
{}

ChannelData::~ChannelData(){}


ChannelMetaData&        ChannelData::getMetaData(void){return metaData;}
ChannelMode&            ChannelData::getMode(void){return mode;}
SubscriptionRepository& ChannelData::getSubscribers(void){return subscribers;}
OperatorsRepository&    ChannelData::getOperators(void){return operators;}

const ChannelMetaData&        ChannelData::getMetaData(void)const {return metaData;}
const ChannelMode&            ChannelData::getMode(void)const {return mode;}
const SubscriptionRepository& ChannelData::getSubscribers(void)const {return subscribers;}
const OperatorsRepository&    ChannelData::getOperators(void)const {return operators;}
