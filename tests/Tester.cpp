#include "../include/Tester.hpp"



void Tester::TClient::test(const std::string& title, const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    try
    {
        Client client(nickname, username, hostname, hostuser);
        std::cout << client ;
    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }
}

void Tester::TClientRepo::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    try
    {
        ClientRepository repository;
        Client client1( "Adam-AK47", "adambrands", "localhost", "debian-13");
        Client client2( "Bob-1337", "bobmarlin", "localhost", "debian-12");
        std::cout << "Number of clients : " << repository.getAllClient().size() << std::endl;
        repository.addClient(client1);
        std::cout << "Number of clients after adding 1st client : " << repository.getAllClient().size() << std::endl;
        repository.addClient(client2);
        std::cout << "Number of clients after adding 2nd client : " << repository.getAllClient().size() << std::endl;
        
        try
        {
            std::cout << "Check for client that exist :" << std::endl;
            std:: cout << "Is there a client called Bob-1337 : " << (repository.hasClient("Bob-1337") ? "YES" : "NO") << std::endl;
            std::cout << "Check for client that is not exist :" << std::endl;
            std:: cout << "Is there a client called Bob-1338 : " << (repository.hasClient("Bob-1338") ? "YES" : "NO") << std::endl;

        } catch (const IllegalArgumentException& e)
        {
            std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
        }

        try
        {
            std::cout << "get client that exist :" << std::endl;
            repository.getClient("Bob-1337");
            std::cout << "get client that is not exist :" << std::endl;
            repository.getClient("Bob-42");

        } catch (const IllegalArgumentException& e)
        {
            std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
        }

        {
            std::cout << "remove client that exist :" << std::endl;
            repository.removeClient("Adam-AK47");
            std::cout << "remove client that is not exist :" << std::endl;
            repository.removeClient("Bob-42");
            std::cout << "Number of clients : " << repository.getAllClient().size() << std::endl;
            std::cout << repository.getClient("Bob-1337");
        }


    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
}

