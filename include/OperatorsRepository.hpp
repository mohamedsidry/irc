#ifndef OPERATORSREPOSITORY_HPP
#define OPERATORSREPOSITORY_HPP


#include <map>
#include <string>
#include "ISearchableClient.hpp"
#include "IClientManagment.hpp"

class Client; // Forward declaration

class OperatorsRepository : public ISearchableClient, public IClientManagment
{
    private:
        std::map<std::string, Client*> clients;
    public:

        OperatorsRepository();
        OperatorsRepository(const OperatorsRepository& copy);
        OperatorsRepository& operator=(const OperatorsRepository& other);
        ~OperatorsRepository();

        bool hasClient(const std::string& nickname) const;
        void removeClient(const std::string& nickname);
        void removeAll(void);
        Client* getClient(const std::string& nickname);
        Client* addClient(Client* client);
        const std::map<std::string, Client*>& getAllClient(void) const;
};

#endif // OPERATORSREPOSITORY_HPP

