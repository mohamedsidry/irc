#include "ChannelData.hpp"
#include "ChannelDataService.hpp"
#include "IllegalArgumentException.hpp"
#include "Utils.hpp"
#include "Channel.hpp"



void ChannelDataService::validateName(const std::string& name) const
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

void ChannelDataService::validateTopic(const std::string& topic) const
{
    if (topic.empty() || Utils::isAllWhitespace(topic))
        throw IllegalArgumentException("Empty channel topic");
    if (topic.size() > Channel::TOPIC_LIMIT)
        throw IllegalArgumentException("Too Long channel topic : " + topic);
}


ChannelDataService::ChannelDataService(ChannelData& data):
data(data)
{
    validateName(data.getChannelName());
    validateTopic(data.getChannelTopic());
}

ChannelDataService::~ChannelDataService(){}


void ChannelDataService::changeName(const std::string& name)
{

    validateName(name);
    data.setChannelName(name);
}

void ChannelDataService::changeTopic(const std::string& topic)
{
    validateTopic(topic);
    data.setChannelTopic(topic);
}


void ChannelDataService::changeKey(const std::string& key)
{
    data.setChannelKey(key);
}

void ChannelDataService::changeLimit(size_t limit)
{
    data.setChannelLimit(limit);
}


const std::string& ChannelDataService::getChannelName(void) const {return data.getChannelName();}
const std::string& ChannelDataService::getChannelTopic(void) const{return data.getChannelTopic();}
const std::string& ChannelDataService::getChannelKey(void) const{return data.getChannelKey();}
size_t ChannelDataService::getChannelLimit(void)const{return data.getChannelLimit();}



