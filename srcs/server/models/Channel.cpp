#include "../../../include/Channel.hpp"
#include "../../../include/Utils.hpp"
#include "../../../include/IllegalArgumentException.hpp"

size_t Channel::NAME_LIMIT = 200;
size_t Channel::TOPIC_LIMIT = 256;
size_t Channel::MAX_SUBSCRIBERS = 256;
std::string Channel::DEFAULT_KEY = "leet@1337";

Channel::Channel(const std::string& name, const std::string& topic)
{
    nameValidation(name);
    this->name = name;
    topicValidation(topic);
    this->topic = topic;
    this->key = Channel::DEFAULT_KEY;
    this->limits = Channel::MAX_SUBSCRIBERS;

}



Channel::~Channel(){}




const std::string& Channel::getChannelName(void) const {return name;}
const std::string& Channel::getChannelTopic(void) const {return topic;}
const std::string& Channel::getChannelKey(void) const {return key;}
size_t Channel::getChannelLimits(void) const {return limits;}
const ChannelModeService& Channel::getChannelModeService(void) const {return modeService;}


void Channel::setChannelName(const std::string& name)
{
    nameValidation(name);
    this->name = name;
}


void Channel::setChannelTopic(const std::string& topic)
{
    topicValidation(topic);
    this->topic = topic;
}


void Channel::setChannelLimits(size_t limit)
{
    this->limits = limit;
}

void Channel::nameValidation(const std::string& name) const
{
    if (name.empty() || Utils::isAllWhitespace(name))
        throw IllegalArgumentException("Empty channel name");
    if (name.size() > Channel::NAME_LIMIT)
        throw IllegalArgumentException("Too Long channel name : " + name);
    if (!Utils::startWith(name, '#') && !Utils::startWith(name, '&'))
        throw IllegalArgumentException("Channel name `" + name + "` should start with # or &");
    if (Utils::hasAtLeastOne(name, '\a'))
        throw IllegalArgumentException("Channel name `" + name + "` should not contain Ctr+G (ascii 7)");
    if (Utils::hasAtLeastOne(name, ','))
        throw IllegalArgumentException("Channel name `" + name + "` should not contain comma (,)");
    if (Utils::hasWhitespace(name))
        throw IllegalArgumentException("Channel name `" + name + "` should not contain space (' ')");
}

void Channel::topicValidation(const std::string& topic) const
{
    if (topic.empty() || Utils::isAllWhitespace(topic))
        throw IllegalArgumentException("Empty channel topic");
    if (topic.size() > Channel::TOPIC_LIMIT)
        throw IllegalArgumentException("Too Long channel topic : " + topic);
}



std::ostream& operator<<(std::ostream& os, const Channel& channel)
{
    os << "CHANNEL NAME : " << channel.getChannelName() << std::endl;
    os << "CHANNEL TOPIC : " << channel.getChannelTopic() << std::endl;
    os << "CHANNEL LIMITS : " << channel.getChannelLimits() << std::endl;
    os << "CHANNEL KEY  : " << channel.getChannelKey() << std::endl;
    os << "CHANNEL MODES  : " << channel.getChannelModeService().getChannelModes();
    return os;
}
