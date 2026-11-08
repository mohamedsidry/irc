
#include "ChannelMode.hpp"
#include "ChannelModeService.hpp"
#include "IllegalArgumentException.hpp"


/**
    v - give/take the ability to speak on a moderated channel;
    o - give/take channel operator privileges;
    l - set the user limit to channel;
    k - set a channel key (password).
    p - private channel flag;
    t - topic settable by channel operator only flag;
    i - invite-only channel flag;
    n - no messages to channel from clients on the outside;
    s - secret channel flag;
    m - moderated channel;
    b - set a ban mask to keep users out;
*/

/**
∗ MODE - Change the channel’s mode:
· i: Set/remove Invite-only channel
· t: Set/remove the restrictions of the TOPIC command to channel operators
· k: Set/remove the channel key (password)
· o: Give/take channel operator privilege
· l: Set/remove the user limit to channel
*/

std::string ChannelModeService::SUPPORTED_OPTIONS = "itkol";
std::string ChannelModeService::DEFAULT_MODE = "t";


ChannelModeService::ChannelModeService():
mode(ChannelModeService::DEFAULT_MODE)
{}



ChannelModeService& ChannelModeService::operator=(const ChannelModeService& other)
{
    if (this != &other)
        this->mode = other.mode;
    return (*this);
}


ChannelModeService::~ChannelModeService(){}


const std::string& ChannelModeService::getChannelModes(void) const
{
    return mode.getFlags();
}


void ChannelModeService::updateChannelMode(const std::string& mode)
{
    size_t adding = 0;
    for (std::string::const_iterator it = mode.begin(); it != mode.end(); it++)
    {
        if (*it == '+' || *it == '-')
            *it == '+' ? adding = true : adding = false;
        else
            adding == true ? addMode(*it) : removeMode(*it);
    }
}

void ChannelModeService::addMode(unsigned char option)
{
    validateOption(option);
    mode.addFlag(option);
}

void ChannelModeService::removeMode(unsigned char option)
{
    if (ChannelModeService::SUPPORTED_OPTIONS.find(option) == std::string::npos)
        throw IllegalArgumentException("Invalid channel mode option : " + std::string(1, option));
    mode.removeFlag(option);
}

bool ChannelModeService::hasMode(unsigned char option) const
{
    return mode.hasFlag(option);
}

void ChannelModeService::validateOption(unsigned char option) const
{
    if (ChannelModeService::SUPPORTED_OPTIONS.find(option) == std::string::npos)
        throw IllegalArgumentException("Invalid channel mode option : " + std::string(1, option));
}

void ChannelModeService::validateMode(const std::string& mode) const
{
    if (mode.empty() || Utils::isAllWhitespace(mode) || (!Utils::startWith(mode, '+') && !Utils::startWith(mode, '-')))
        throw IllegalArgumentException("Invalid channel mode : " + mode);
    for (std::string::const_iterator it = mode.begin(); it != mode.end(); it++)
    {
        if (*it == '+' || *it == '-')
            continue;
        validateOption(*it);
    }
}
