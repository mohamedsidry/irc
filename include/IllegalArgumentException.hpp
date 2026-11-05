#pragma once

#include "main.hpp"

class IllegalArgumentException: public Exception
{
    public:
        explicit IllegalArgumentException(const std::string& message): Exception("IllegalArgumentException : " + message){}
};

