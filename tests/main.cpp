#include "../include/main.hpp"
#include "../include/test.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << "\033[1;32m" << "-- RUNNING TESTS --" << "\033[0m" << std::endl;
    Client client("Adam-AK47", "adambrands", "localhost", "debian-13");
    std::cout << client;
    return (EXIT_SUCCESS);
}
