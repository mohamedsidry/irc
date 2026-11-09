#pragma once

#include <iostream>
#include <string>
#include <cstddef>

#include "ChannelModeService.hpp"
#include "ChannelMetaDataService.hpp"
#include "ChannelMetaData.hpp"
#include "SubscriptionRepository.hpp"
#include "SubscriptionService.hpp"
#include "OperatorsRepository.hpp"
#include "OperateService.hpp"

class Channel
{
    private:
        ChannelMetaData         data;
        ChannelMetaDataService  dataService;
        ChannelMode         mode;
        ChannelModeService  modeService;
        SubscriptionRepository subscribers;
        SubscriptionService subsService;
        OperatorsRepository operators;
        OperateService      operateService; 
        Channel();
        Channel(const Channel& copy);
        Channel& operator=(const Channel&);

    public:
        Channel(const std::string& name, const std::string& topic);
        ~Channel();
        static const size_t NAME_LIMIT = 200;
        static const size_t TOPIC_LIMIT = 256;
        static const size_t DEFAULT_SUBSCRIBERS_LIMIT = 1024;
        static const std::string DEFAULT_KEY;
        static const std::string DEFAULT_MODE;
        static const std::string SUPPORTED_MODES;
        friend std::ostream& operator<<(std::ostream& os, const Channel& ref);
};

