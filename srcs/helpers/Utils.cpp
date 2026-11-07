#include "../../include/main.hpp"





bool Utils::isAllWhitespace(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return false;
    return true;
}


bool Utils::hasOnly(const std::string& src, const std::string& set)
{
    if (set.empty() || src.empty())
        return false;
    for (std::string::const_iterator it = src.begin(); it != src.end(); ++it)
    {
        if (set.find(*it) == std::string::npos)
            return false;
    }
    return true;
}

