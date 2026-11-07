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
        static bool hasOnly(const std::string& src, const std::string& set);
};
