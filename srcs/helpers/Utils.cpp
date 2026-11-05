#include "../../include/main.hpp"





bool Utils::isAllWhitespace(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return false;
    return true;
}

