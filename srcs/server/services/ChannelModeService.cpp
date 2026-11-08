
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


void ChannelModeService::updateChannelMode(const std::string& option)
{
    if(validOption(option))
        return option[0] == '+' ? mode.addFlag(option[1]) : mode.removeFlag(option[1]);
    throw IllegalArgumentException("Invalid channel mode option : " + option);
}

bool ChannelModeService::validOption(const std::string& option) const
{
    if (option.size() != 2)
        return false;

    if (option[0] != '+' && option[0] != '-')
        return false;

    if (ChannelModeService::SUPPORTED_OPTIONS.find(option[1]) == std::string::npos)
        return false;

    return true;
}

