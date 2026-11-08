#include "../../../include/Channel.hpp"
#include "../../../include/Utils.hpp"
#include "../../../include/IllegalArgumentException.hpp"

const std::string Channel::DEFAULT_KEY = "leet@1337";
const std::string Channel::DEFAULT_MODE = "t";
const std::string Channel::SUPPORTED_MODES = "itkol";

Channel::Channel(const std::string& name, const std::string& topic):
data(name, topic, Channel::DEFAULT_KEY, Channel::DEFAULT_SUBSCRIBERS_LIMIT),
dataService(data),
mode(Channel::DEFAULT_MODE),
modeService(mode)
{}


Channel::~Channel(){}


std::ostream& operator<<(std::ostream& os, const Channel& channel)
{
    os << "CHANNEL NAME : " << channel.dataService.getChannelName() << std::endl;
    os << "CHANNEL TOPIC : " << channel.dataService.getChannelTopic() << std::endl;
    os << "CHANNEL LIMITS : " << channel.dataService.getChannelLimit() << std::endl;
    os << "CHANNEL KEY  : " << channel.dataService.getChannelKey() << std::endl;
    os << "CHANNEL MODES  : " << channel.modeService.getChannelModes();
    return os;
}
