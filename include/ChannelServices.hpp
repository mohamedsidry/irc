#pragma once

#include "ChannelMetaDataService.hpp"
#include "ChannelModeService.hpp"
#include "SubscriptionService.hpp"
#include "OperateService.hpp"
#include "ChannelData.hpp"

class ChannelServices
{
    private:
        ChannelMetaDataService  metaDataService;
        ChannelModeService      modeService;
        SubscriptionService     subscriptionService;
        OperateService          operateService;
        ChannelServices();
    public:
        ChannelServices(ChannelData& data);
        ~ChannelServices();

        ChannelMetaDataService& getMetaDataService(void);
        ChannelModeService& getModeService(void);
        SubscriptionService& getSubscriptionService(void);
        OperateService& getOperateService(void);

        const ChannelMetaDataService& getMetaDataService(void)const ;
        const ChannelModeService& getModeService(void)const ;
        const SubscriptionService& getSubscriptionService(void)const ;
        const OperateService& getOperateService(void)const ;
};

