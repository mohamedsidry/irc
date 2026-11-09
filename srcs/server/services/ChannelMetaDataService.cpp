#include "ChannelMetaData.hpp"
#include "ChannelMetaDataService.hpp"
#include "IllegalArgumentException.hpp"
#include "Utils.hpp"
#include "Channel.hpp"



void ChannelMetaDataService::validateName(const std::string& name) const
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

void ChannelMetaDataService::validateTopic(const std::string& topic) const
{
    if (topic.empty() || Utils::isAllWhitespace(topic))
        throw IllegalArgumentException("Empty channel topic");
    if (topic.size() > Channel::TOPIC_LIMIT)
        throw IllegalArgumentException("Too Long channel topic : " + topic);
}


ChannelMetaDataService::ChannelMetaDataService(ChannelMetaData& data):
data(data)
{
    validateName(data.getChannelName());
    validateTopic(data.getChannelTopic());
}

ChannelMetaDataService::~ChannelMetaDataService(){}


void ChannelMetaDataService::changeName(const std::string& name)
{

    validateName(name);
    data.setChannelName(name);
}

void ChannelMetaDataService::changeTopic(const std::string& topic)
{
    validateTopic(topic);
    data.setChannelTopic(topic);
}


void ChannelMetaDataService::changeKey(const std::string& key)
{
    data.setChannelKey(key);
}

void ChannelMetaDataService::changeLimit(size_t limit)
{
    data.setChannelLimit(limit);
}


const std::string& ChannelMetaDataService::getChannelName(void) const {return data.getChannelName();}
const std::string& ChannelMetaDataService::getChannelTopic(void) const{return data.getChannelTopic();}
const std::string& ChannelMetaDataService::getChannelKey(void) const{return data.getChannelKey();}
size_t ChannelMetaDataService::getChannelLimit(void)const{return data.getChannelLimit();}



