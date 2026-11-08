#include "../../../include/ChannelData.hpp"


ChannelData::ChannelData(const std::string& name, const std::string& topic, const std::string& key, size_t limit):
name(name),
topic(topic),
key(key),
limit(limit)
{}


ChannelData::ChannelData(const ChannelData& copy):
name(copy.name),
topic(copy.topic),
key(copy.key),
limit(copy.limit)
{}


ChannelData& ChannelData::operator=(const ChannelData& other)
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

ChannelData::~ChannelData(){}


const std::string& ChannelData::getChannelName(void) const {return name;}
const std::string& ChannelData::getChannelTopic(void) const {return topic;}
const std::string& ChannelData::getChannelKey(void) const {return key;}
size_t ChannelData::getChannelLimit(void) const {return limit;}

void ChannelData::setChannelName(const std::string& name)  {this->name = name;}
void ChannelData::setChannelTopic(const std::string& topic)  {this->topic = topic;}
void ChannelData::setChannelKey(const std::string& key)  {this->key = key;}
void ChannelData::setChannelLimit(size_t limit)  {this->limit = limit;}



std::ostream& operator<<(std::ostream& os, const ChannelData& ref)
{
    os << "CHANNEL NAME : " << ref.getChannelName() << std::endl;
    os << "CHANNEL TOPIC : " << ref.getChannelTopic() << std::endl;
    os << "CHANNEL KEY  : " << ref.getChannelKey() << std::endl;
    os << "CHANNEL LIMITS : " << ref.getChannelLimit() << std::endl;
    return os;
}

