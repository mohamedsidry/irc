#pragma once

#include "Exception.hpp"

class IllegalArgumentException: public Exception
{
    public:
        explicit IllegalArgumentException(const std::string& message): Exception("IllegalArgumentException : " + message){}
};

