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
        ChannelModeService  modeService;

        Channel();
        Channel(const Channel& copy);
        Channel& operator=(const Channel&);

    public:
        Channel(const std::string& name, const std::string& topic);
        ~Channel();

        const ChannelModeService& getChannelModeService(void) const;

        static size_t NAME_LIMIT;
        static size_t TOPIC_LIMIT;
        static size_t SUBSCRIBERS_LIMIT;
        static std::string DEFAULT_KEY;
        friend std::ostream& operator<<(std::ostream& os, const Channel& ref);
};

