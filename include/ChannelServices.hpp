
#ifndef CHANNELSERVICES_HPP
#define CHANNELSERVICES_HPP

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
        
        ChannelServices(const ChannelServices&);
        ChannelServices& operator=(const ChannelServices&);
    public:
        ChannelServices(ChannelData& data);

        ChannelMetaDataService& getMetaDataService(void);
        ChannelModeService& getModeService(void);
        SubscriptionService& getSubscriptionService(void);
        OperateService& getOperateService(void);

        const ChannelMetaDataService& getMetaDataService(void)const ;
        const ChannelModeService& getModeService(void)const ;
        const SubscriptionService& getSubscriptionService(void)const ;
        const OperateService& getOperateService(void)const ;
};

#endif // CHANNELSERVICES_HPP

