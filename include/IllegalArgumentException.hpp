#ifndef ILLEGALARGUMENTEXCEPTION_HPP
#define ILLEGALARGUMENTEXCEPTION_HPP

#include "Exception.hpp"

class IllegalArgumentException: public Exception
{
    public:
        explicit IllegalArgumentException(const std::string& message): Exception("IllegalArgumentException : " + message){}
};


#endif // ILLEGALARGUMENTEXCEPTION_HPP


