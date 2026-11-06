#include "../include/test.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << "\033[1;32m" << "-- RUNNING TESTS --" << "\033[0m" << std::endl;
    Tester::TClient::test("Valid Nickname", "Adam-AK47", "adambrands", "localhost", "debian-13");
    Tester::TClient::test("Empty Nickname", "", "adambrands", "localhost", "debian-13");
    Tester::TClient::test("Space Nickname", "\t  \n", "adambrands", "localhost", "debian-13");
    Tester::TClient::test("Long Nickname", "Adam-AK474747", "adambrands", "localhost", "debian-13");
    return (EXIT_SUCCESS);
}
