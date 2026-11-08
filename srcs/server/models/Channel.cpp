#include "../../../include/Channel.hpp"
#include "../../../include/Utils.hpp"
#include "../../../include/IllegalArgumentException.hpp"

size_t Channel::NAME_LIMIT = 200;
size_t Channel::TOPIC_LIMIT = 256;
size_t Channel::SUBSCRIBERS_LIMIT = 256;
std::string Channel::DEFAULT_KEY = "leet@1337";

Channel::Channel(const std::string& name, const std::string& topic):
data(name, topic, Channel::DEFAULT_KEY, Channel::SUBSCRIBERS_LIMIT),
dataService(data)
{
    //this->data = ChannelData(name, topic, Channel::DEFAULT_KEY, Channel::SUBSCRIBERS_LIMIT);
    //this->dataService = ChannelDataService(this->data);
}


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
