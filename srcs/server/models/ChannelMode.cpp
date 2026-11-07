#include "../../../include/ChannelMode.hpp"


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

std::string ChannelMode::SUPPORTED_MODES = "itkol";
std::string ChannelMode::DEFAULT_MODES = "t";



ChannelMode::ChannelMode(): flags(ChannelMode::DEFAULT_MODES){}




ChannelMode::ChannelMode(const std::string& options)
{
    modeValidation(options);
    flags = options;
}


ChannelMode::ChannelMode(const ChannelMode& copy): flags(copy.flags){}


ChannelMode& ChannelMode::operator=(const ChannelMode& other)
{
    if (this != &other)
        this->flags = other.flags;
    return *this;
}


ChannelMode::~ChannelMode(){}




const std::string& ChannelMode::getModes(void) const
{
    return flags;
}


void ChannelMode::setMode(const std::string& mode)
{
    modeValidation(mode);
    this->flags = mode;
}




void ChannelMode::modeValidation(const std::string& options) const
{
    if (options.empty() || Utils::isAllWhitespace(options))
        throw IllegalArgumentException("Set empty mode to channel");
    if (!Utils::hasOnly(options, ChannelMode::SUPPORTED_MODES))
        throw IllegalArgumentException("Set unsupported option to channel mode : " + options);
}

void ChannelMode::updateMode(const std::string& option)
{
    if (option.empty())
        return;

    if (!validOption(option))
        throw IllegalArgumentException("Invalid channel mode option : " + option);

    std::string::size_type pos = flags.find(option[1]);

    if (option[0] == '+')
    {
        if (pos == std::string::npos)
            flags.append(1, option[1]);
    }
    else if (option[0] == '-')
    {
        if (pos != std::string::npos)
            flags.erase(pos, 1);
    }
}

bool ChannelMode::validOption(const std::string& option) const
{
    if (option.size() != 2)
        return false;

    if (option[0] != '+' && option[0] != '-')
        return false;

    if (ChannelMode::SUPPORTED_MODES.find(option[1]) == std::string::npos)
        return false;

    return true;
}



bool ChannelMode::hasOption(unsigned char opt) const
{
    return flags.find(opt) != std::string::npos ? true : false;
}

