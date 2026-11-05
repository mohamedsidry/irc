#pragma once

#include "main.hpp"


class Utils
{
    private:
        Utils();
        Utils(const Utils&);
        Utils& operator=(const Utils&);
        ~Utils();
    public:
        static bool isAllWhitespace(const std::string& str);
};
