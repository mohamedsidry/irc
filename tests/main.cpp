#include "../include/main.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << "\033[1;32m" << "-- RUNNING TESTS --" << "\033[0m" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << "\033[1;32m" << "TEST  ==>   " << i << "\033[0m" << std::endl;
    return (EXIT_SUCCESS);
}
