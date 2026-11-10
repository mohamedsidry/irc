#include "ChannelData.hpp"


ChannelData::ChannelData(const std::string& metaName, const std::string& metaTopic, const std::string& metaKey, std::size_t metaLimit, const std::string& initialMode):
metaData(metaName, metaTopic, metaKey, metaLimit),
mode(initialMode),
subscribers(),
moderators()
{}


ChannelMetaData&        ChannelData::getMetaData(void){return metaData;}
ChannelMode&            ChannelData::getMode(void){return mode;}
SubscribersRepository& ChannelData::getSubscribers(void){return subscribers;}
ModeratorsRepository&    ChannelData::getOperators(void){return operators;}

const ChannelMetaData&        ChannelData::getMetaData(void)const {return metaData;}
const ChannelMode&            ChannelData::getMode(void)const {return mode;}
const SubscribersRepository& ChannelData::getSubscribers(void)const {return subscribers;}
const ModeratorsRepository&    ChannelData::getOperators(void)const {return operators;}
