#pragma once

#include <string>

class Client; // Forward declaration
class OperatorsRepository;


class OperateService
{
    
    private:
        OperatorsRepository& repository;
        OperateService(const OperateService& copy); // delete
        OperateService& operator=(const OperateService& other); // delete
    public:
        OperateService(OperatorsRepository& repository);
        ~OperateService();
        Client* startOperating(Client* client);
        void stopOperating(Client* client);
        void stopOperating(const std::string& nickname);
        bool isOperator(Client* client) const;
        bool isOperator(const std::string& nickname) const;
        void stopAllOperators(void);
};
