#include "../../../include/ChannelMetaData.hpp"


ChannelMetaData::ChannelMetaData(const std::string& name, const std::string& topic, const std::string& key, size_t limit):
name(name),
topic(topic),
key(key),
limit(limit)
{}


ChannelMetaData::ChannelMetaData(const ChannelMetaData& copy):
name(copy.name),
topic(copy.topic),
key(copy.key),
limit(copy.limit)
{}


ChannelMetaData& ChannelMetaData::operator=(const ChannelMetaData& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->topic = other.topic;
        this->key = other.key;
        this->limit = other.limit;
    }
    return (*this);
}

ChannelMetaData::~ChannelMetaData(){}


const std::string& ChannelMetaData::getChannelName(void) const {return name;}
const std::string& ChannelMetaData::getChannelTopic(void) const {return topic;}
const std::string& ChannelMetaData::getChannelKey(void) const {return key;}
size_t ChannelMetaData::getChannelLimit(void) const {return limit;}

void ChannelMetaData::setChannelName(const std::string& name)  {this->name = name;}
void ChannelMetaData::setChannelTopic(const std::string& topic)  {this->topic = topic;}
void ChannelMetaData::setChannelKey(const std::string& key)  {this->key = key;}
void ChannelMetaData::setChannelLimit(size_t limit)  {this->limit = limit;}



std::ostream& operator<<(std::ostream& os, const ChannelMetaData& ref)
{
    os << "CHANNEL NAME : " << ref.getChannelName() << std::endl;
    os << "CHANNEL TOPIC : " << ref.getChannelTopic() << std::endl;
    os << "CHANNEL KEY  : " << ref.getChannelKey() << std::endl;
    os << "CHANNEL LIMITS : " << ref.getChannelLimit() << std::endl;
    return os;
}

