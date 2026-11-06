#pragma once

#include "main.hpp"

class Client; // Forward declaration

class IClientManagment
{
    public:
        virtual ~IClientManagment(){}
        virtual void addClient(const Client& client) = 0;
        virtual void removeClient(const std::string& nickname) = 0;
};

