#pragma once

#include <string>

class Client; // Forward declaration

class ISearchableClient
{
    public:
        virtual ~ISearchableClient(){}
        virtual bool hasClient(const std::string& nickname) const = 0;
        virtual Client* getClient(const std::string& nickname) = 0;
};

