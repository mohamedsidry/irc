#include "ChannelServices.hpp"


ChannelServices::ChannelServices(ChannelData& data):
metaDataService(data.getMetaData()),
modeService(data.getMode()),
subscribersService(data.getSubscribers()),
operateService(data.getOperators())
{}




ChannelMetaDataService& ChannelServices::getMetaDataService(void){return metaDataService;}
ChannelModeService& ChannelServices::getModeService(void){return modeService;}
SubscribersService& ChannelServices::getSubscribersService(void){return subscribersService;}
OperateService& ChannelServices::getOperateService(void){return operateService;}


const ChannelMetaDataService& ChannelServices::getMetaDataService(void)const {return metaDataService;}
const ChannelModeService& ChannelServices::getModeService(void)const {return modeService;}
const SubscribersService& ChannelServices::getSubscribersService(void)const {return subscribersService;}
const OperateService& ChannelServices::getOperateService(void)const {return operateService;}

