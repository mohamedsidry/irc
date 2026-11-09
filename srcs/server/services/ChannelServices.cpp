#include "ChannelServices.hpp"


ChannelServices::ChannelServices(ChannelData& data):
metaDataService(data.getMetaData()),
modeService(data.getMode()),
subscriptionService(data.getSubscribers()),
operateService(data.getOperators())
{}




ChannelMetaDataService& ChannelServices::getMetaDataService(void){return metaDataService;}
ChannelModeService& ChannelServices::getModeService(void){return modeService;}
SubscriptionService& ChannelServices::getSubscriptionService(void){return subscriptionService;}
OperateService& ChannelServices::getOperateService(void){return operateService;}


const ChannelMetaDataService& ChannelServices::getMetaDataService(void)const {return metaDataService;}
const ChannelModeService& ChannelServices::getModeService(void)const {return modeService;}
const SubscriptionService& ChannelServices::getSubscriptionService(void)const {return subscriptionService;}
const OperateService& ChannelServices::getOperateService(void)const {return operateService;}

