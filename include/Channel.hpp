#pragma once

#include <iostream>
#include <string>
#include <cstddef>

#include "ChannelModeService.hpp"
#include "ChannelDataService.hpp"
#include "ChannelData.hpp"

class Channel
{
    private:
        ChannelData         data;
        ChannelDataService  dataService;
        ChannelMode         mode;
        ChannelModeService  modeService;

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

