#pragma once

#include <string>

class Client; // Forward declaration

class ISearchableClient
{
    public:
        virtual ~ISearchableClient(){}
        virtual bool hasClient(const std::string& nickname) const = 0;
        virtual const Client& getClient(const std::string& nickname) const = 0;
};

