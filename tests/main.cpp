#include "test.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << "\033[1;32m" << "-- RUNNING TESTS --" << "\033[0m" << std::endl;
    Tester::TClient::test("Valid Nickname", "Adam-AK47", "adambrands", "localhost", "debian-13");
    Tester::TClient::test("Empty Nickname", "", "adambrands", "localhost", "debian-13");
    Tester::TClient::test("Space Nickname", "\t  \n", "adambrands", "localhost", "debian-13");
    Tester::TClient::test("Long Nickname", "Adam-AK474747", "adambrands", "localhost", "debian-13");
    Tester::TClientsRepo::test("Clients Repository Testing");
    Tester::TClientsService::test("Clients Service Testing");
    //Tester::TChannelMetaData::test("Channel MetaData Testing ");
    //Tester::TChannelMetaDataService::test("Channel MetaData Service Testing");
    //Tester::TChannelMode::test("ChannelModes Testing");
    //Tester::TChannelModeService::test("ChannelModes Service Testing");
    Tester::TSubscribersRepo::test("Subscribers Repository Testing");
    Tester::TSubscribersService::test("Subscribers Service Testing");
    Tester::TModeratorsRepo::test("Moderators Repository Testing");
    Tester::TModeratorsService::test("Moderators Service Testing");
    //Tester::TChannel::test("FULL CHANNEL");
    return (EXIT_SUCCESS);
}
