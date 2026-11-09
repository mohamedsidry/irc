#include "Channel.hpp"

const std::string Channel::DEFAULT_KEY = "leet@1337";
const std::string Channel::DEFAULT_MODE = "t";
const std::string Channel::SUPPORTED_MODES = "itkol";

Channel::Channel(const std::string& name, const std::string& topic):
data(name, topic, DEFAULT_KEY, DEFAULT_SUBSCRIBERS_LIMIT, DEFAULT_MODE),
services(data)
{}

Channel::~Channel()
{}

ChannelServices& Channel::getServices(void)
{
    return services;
}

const ChannelServices& Channel::getServices(void) const
{
    return services;
}

std::ostream& operator<<(std::ostream& os, const Channel& channel)
{
    const ChannelServices& services = channel.getServices();

    os << "CHANNEL NAME   : "
       << services.getMetaDataService().getChannelName() << '\n';

    os << "CHANNEL TOPIC  : "
       << services.getMetaDataService().getChannelTopic() << '\n';

    os << "CHANNEL KEY    : "
       << services.getMetaDataService().getChannelKey() << '\n';

    os << "CHANNEL LIMITS : "
       << services.getMetaDataService().getChannelLimit() << '\n';

    os << "CHANNEL MODES  : "
       << services.getModeService().getChannelModes() << '\n';

    return os;
}
