
#ifndef CHANNELSERVICES_HPP
#define CHANNELSERVICES_HPP

#include "ChannelMetaDataService.hpp"
#include "ChannelModeService.hpp"
#include "SubscribersService.hpp"
#include "ModeratorsService.hpp"
#include "ChannelData.hpp"

class ChannelServices
{
    private:
        ChannelMetaDataService  metaDataService;
        ChannelModeService      modeService;
        SubscribersService     subscribersService;
        ModeratorsService          moderatorsService;
        
        ChannelServices(const ChannelServices&);
        ChannelServices& operator=(const ChannelServices&);
    public:
        ChannelServices(ChannelData& data);

        ChannelMetaDataService& getMetaDataService(void);
        ChannelModeService& getModeService(void);
        SubscribersService& getSubscribersService(void);
        ModeratorsService& getModeratorsService(void);

        const ChannelMetaDataService& getMetaDataService(void)const ;
        const ChannelModeService& getModeService(void)const ;
        const SubscribersService& getSubscribersService(void)const ;
        const ModeratorsService& getModeratorsService(void)const ;
};

#endif // CHANNELSERVICES_HPP

