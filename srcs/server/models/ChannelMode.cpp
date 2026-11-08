#include "../../../include/ChannelMode.hpp"
#include "../../../include/Utils.hpp"

ChannelMode::ChannelMode(const std::string& flags):
flags(flags)
{}


ChannelMode::ChannelMode(const ChannelMode& copy): flags(copy.flags){}


ChannelMode& ChannelMode::operator=(const ChannelMode& other)
{
    if (this != &other)
        this->flags = other.flags;
    return *this;
}


ChannelMode::~ChannelMode(){}


const std::string& ChannelMode::getFlags(void) const
{
    return flags;
}


void ChannelMode::addFlag(unsigned char flag)
{
    if(!hasFlag(flag))
        flags.append(1,flag);
}

void ChannelMode::removeFlag(unsigned char flag)
{
    std::string::size_type pos = flags.find(flag);

    if (pos != std::string::npos)
        flags.erase(pos, 1);
}


bool ChannelMode::hasFlag(unsigned char flag) const
{
    return flags.find(flag) != std::string::npos ? true : false;
}
