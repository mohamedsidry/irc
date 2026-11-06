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

