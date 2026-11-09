#include "Tester.hpp"



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
        Client *client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
        Client *client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-12");
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
            std::cout << *repository.getClient("Bob-1337");
        }


    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
}



void Tester::TClientService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ClientRepository repository;
    ClientService service(repository);

    try{service.addClient("Adam-AK1", "adambrands", "localhost", "debian-13");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.addClient("Adam-AK1", "adambrands", "localhost", "debian-13");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.addClient("Adam-AK10", "adambrands", "localhost", "debian-13");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.addClient("Adam-AK100", "adambrands", "localhost", "debian-13");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.removeClient("Adam-AK1");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.removeClient("Adam-AK10");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.addClient("Adam-AK1", "adambrands", "localhost", "debian-13");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.findClient("Adam-AK99");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.addClient("Adam-AK99", "adambrands", "localhost", "debian-13");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    try{service.findClient("Adam-AK99");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
}

void Tester::TChannelMetaData::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ChannelMetaData data("Denzel Washinton", "Equalizer 1", "ifyouprayforraindealwithmud", 1024);
    std::cout << data;

}


void Tester::TChannelMetaDataService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ChannelMetaData vdata("#General", "this channel is for free speech...", "BE-free-4-ever", 256);
    ChannelMetaData fdata("Broken--", "this is channel with broken name ...", "brookkeeen", 256);
    try
    {
        ChannelMetaDataService vv(vdata);
        std::cout << "Channel Name : " << vv.getChannelName() << std::endl;
        std::cout << "Channel Topic : " << vv.getChannelTopic() << std::endl;
        std::cout << "Channel Key : " << vv.getChannelKey() << std::endl;
        std::cout << "Channel Limit : " << vv.getChannelLimit() << std::endl;

    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        ChannelMetaDataService ff(fdata);
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

}



void Tester::TChannelMode::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ChannelMode mode("t");
    std::cout << "ChannelMode flags : " << mode.getFlags() << std::endl;
    mode.addFlag('i');
    mode.addFlag('t');
    mode.addFlag('k');
    mode.addFlag('o');
    mode.addFlag('l');
    mode.addFlag('l');
    mode.addFlag('l');
    std::cout << "ChannelMode flags : " << mode.getFlags() << std::endl;
    mode.removeFlag('l');
    mode.removeFlag('o');
    mode.removeFlag('k');
    mode.removeFlag('t');
    std::cout << "ChannelMode flags : " << mode.getFlags() << std::endl;
    std::cout << "has flag {i} : " << (mode.hasFlag('i') ? "YES" : "NO") << std::endl;
}


void Tester::TChannelModeService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ChannelMode mode("t");
    ChannelModeService service(mode);
    /**
    ∗ MODE - Change the channel’s mode:
    · i: Set/remove Invite-only channel
    · t: Set/remove the restrictions of the TOPIC command to channel operators
    · k: Set/remove the channel key (password)
    · o: Give/take channel operator privilege
    · l: Set/remove the user limit to channel
*/

    std::cout << "Default channel mode : " << service.getChannelModes() << std::endl;
    try{service.addMode('i');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.addMode('j');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.addMode('k');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.addMode('l');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.addMode('m');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.addMode('o');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    std::cout << "channel mode +i +j +k +l +m +o  : " << service.getChannelModes() << std::endl;
    
    try{service.removeMode('i');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.removeMode('j');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.removeMode('k');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try{service.removeMode('l');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.removeMode('m');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try{service.removeMode('o');}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << "channel mode  -j -k -l -m -o  : " << service.getChannelModes() << std::endl;
    
    try{service.updateChannelMode("+iklot");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "channel mode  +iklot  : " << service.getChannelModes() << std::endl;

    try{service.updateChannelMode("-iklot");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "channel mode  -iklot  : " << service.getChannelModes() << std::endl;

    try{service.updateChannelMode("+iklot");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "channel mode  +iklot  : " << service.getChannelModes() << std::endl;

    try{service.updateChannelMode("+i-kl+ot");}
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "channel mode  +i-kl+ot  : " << service.getChannelModes() << std::endl;
    std::cout << "channel mode  has i  : " << (service.hasMode('i') ? "YES" : "NO") << std::endl;

}



void Tester::TSubscriptionRepo::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;

    SubscriptionRepository repository;
    Client *client1 = NULL;
    Client *client2 = NULL;
    client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
    client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-12");
    std::cout << "Number of subscribers : " << repository.getAllClient().size() << std::endl;
    repository.addClient(client1);
    std::cout << "Number of subscribers after adding 1st subscriber : " << repository.getAllClient().size() << std::endl;
    repository.addClient(client2);
    std::cout << "Number of subscribers after adding 2nd subscriber : " << repository.getAllClient().size() << std::endl;
    
    try
    {
        std::cout << "Check for subscriber that exist :" << std::endl;
        std:: cout << "Is there a subscriber called Bob-1337 : " << (repository.hasClient("Bob-1337") ? "YES" : "NO") << std::endl;
        std::cout << "Check for subscriber that is not exist :" << std::endl;
        std:: cout << "Is there a subscriber called Bob-1338 : " << (repository.hasClient("Bob-1338") ? "YES" : "NO") << std::endl;

    } catch (const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }

    try
    {
        std::cout << "get subscriber that exist :" << std::endl;
        repository.getClient("Bob-1337");
        std::cout << "get subscriber that is not exist :" << std::endl;
        repository.getClient("Bob-42");

    } catch (const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }

    try
    {
        std::cout << "remove subscriber that exist :" << std::endl;
        repository.removeClient("Adam-AK47");
        std::cout << "remove subscriber that is not exist :" << std::endl;
        repository.removeClient("Bob-42");
        std::cout << "Number of subscribers : " << repository.getAllClient().size() << std::endl;
        std::cout << *repository.getClient("Bob-1337");

    } catch (const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
    delete client1;
    delete client2;
}


void Tester::TSubscriptionService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    SubscriptionRepository repository;
    SubscriptionService service(repository);

    Client *client1 = NULL;
    Client *client2 = NULL;
    Client *client3 = NULL;
    client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
    client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-14");
    client3 = new Client("Steve-HRV", "steve-harvy", "localhost", "debian-15");



    try
    {
        service.subscribe(client1);
        std::cout << *client1;
        std::cout << client1->getNickName() << " is Subscribed : " << (service.isSubscribed(client1) ? "YES" : "NO") << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try
    {
        service.subscribe(client2);
        std::cout << *client2;
        std::cout << client2->getNickName() << " is Subscribed : " << (service.isSubscribed(client2) ? "YES" : "NO") << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    
    try
    {
        std::cout << *client3;
        std::cout << client3->getNickName() << " is Subscribed : " << (service.isSubscribed(client3) ? "YES" : "NO") << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.subscribe(client3);
        std::cout << *client3;
        std::cout << client3->getNickName() << " is Subscribed : " << (service.isSubscribed(client3) ? "YES" : "NO") << std::endl;
        service.unsubscribe(client3);
        std::cout << client3->getNickName() << " is Subscribed : " << (service.isSubscribed(client3->getNickName()) ? "YES" : "NO") << std::endl;

    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.subscribe(client1);
        service.subscribe(client2);
        service.subscribe(client3);
        std::cout << client1->getNickName() << " is Subscribed : " << (service.isSubscribed(client1) ? "YES" : "NO") << std::endl;
        std::cout << client2->getNickName() << " is Subscribed : " << (service.isSubscribed(client2) ? "YES" : "NO") << std::endl;
        std::cout << client3->getNickName() << " is Subscribed : " << (service.isSubscribed(client3) ? "YES" : "NO") << std::endl;
        std::cout << "Unsubscribe All" << std::endl;
        service.unsubscribeAll();
        std::cout << client1->getNickName() << " is Subscribed : " << (service.isSubscribed(client1) ? "YES" : "NO") << std::endl;
        std::cout << client2->getNickName() << " is Subscribed : " << (service.isSubscribed(client2) ? "YES" : "NO") << std::endl;
        std::cout << client3->getNickName() << " is Subscribed : " << (service.isSubscribed(client3) ? "YES" : "NO") << std::endl;



    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}


    delete client1;
    delete client2;
    delete client3;
}


void Tester::TOperatorsRepo::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;

    OperatorsRepository repository;
    Client *client1 = NULL;
    Client *client2 = NULL;
    client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
    client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-12");
    std::cout << "Number of operators : " << repository.getAllClient().size() << std::endl;
    repository.addClient(client1);
    std::cout << "Number of operators after adding 1st operator : " << repository.getAllClient().size() << std::endl;
    repository.addClient(client2);
    std::cout << "Number of operators after adding 2nd operator : " << repository.getAllClient().size() << std::endl;
    
    try
    {
        std::cout << "Check for operator that exist :" << std::endl;
        std:: cout << "Is there a operator called Bob-1337 : " << (repository.hasClient("Bob-1337") ? "YES" : "NO") << std::endl;
        std::cout << "Check for operator that is not exist :" << std::endl;
        std:: cout << "Is there a operator called Bob-1338 : " << (repository.hasClient("Bob-1338") ? "YES" : "NO") << std::endl;

    } catch (const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }

    try
    {
        std::cout << "get operator that exist :" << std::endl;
        repository.getClient("Bob-1337");
        std::cout << "get operator that is not exist :" << std::endl;
        repository.getClient("Bob-42");

    } catch (const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }

    try
    {
        std::cout << "remove operator that exist :" << std::endl;
        repository.removeClient("Adam-AK47");
        std::cout << "remove operator that is not exist :" << std::endl;
        repository.removeClient("Bob-42");
        std::cout << "Number of operators : " << repository.getAllClient().size() << std::endl;
        std::cout << *repository.getClient("Bob-1337");

    } catch (const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
    delete client1;
    delete client2;
}


void Tester::TOperateService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    OperatorsRepository repository;
    OperateService service(repository);

    Client *client1 = NULL;
    Client *client2 = NULL;
    Client *client3 = NULL;
    client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
    client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-14");
    client3 = new Client("Steve-HRV", "steve-harvy", "localhost", "debian-15");



    try
    {
        service.startOperating(client1);
        std::cout << *client1;
        std::cout << client1->getNickName() << " is Operator : " << (service.isOperator(client1) ? "YES" : "NO") << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try
    {
        service.startOperating(client2);
        std::cout << *client2;
        std::cout << client2->getNickName() << " is Operator : " << (service.isOperator(client2) ? "YES" : "NO") << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    
    try
    {
        std::cout << *client3;
        std::cout << client3->getNickName() << " is Operator : " << (service.isOperator(client3) ? "YES" : "NO") << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.startOperating(client3);
        std::cout << *client3;
        std::cout << client3->getNickName() << " is Operator : " << (service.isOperator(client3) ? "YES" : "NO") << std::endl;
        service.stopOperating(client3);
        std::cout << client3->getNickName() << " is Operator : " << (service.isOperator(client3->getNickName()) ? "YES" : "NO") << std::endl;

    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.startOperating(client1);
        service.startOperating(client2);
        service.startOperating(client3);
        std::cout << client1->getNickName() << " is Operator : " << (service.isOperator(client1) ? "YES" : "NO") << std::endl;
        std::cout << client2->getNickName() << " is Operator : " << (service.isOperator(client2) ? "YES" : "NO") << std::endl;
        std::cout << client3->getNickName() << " is Operator : " << (service.isOperator(client3) ? "YES" : "NO") << std::endl;
        std::cout << "Stop All Operators" << std::endl;
        service.stopAllOperators();
        std::cout << client1->getNickName() << " is Operator : " << (service.isOperator(client1) ? "YES" : "NO") << std::endl;
        std::cout << client2->getNickName() << " is Operator : " << (service.isOperator(client2) ? "YES" : "NO") << std::endl;
        std::cout << client3->getNickName() << " is Operator : " << (service.isOperator(client3) ? "YES" : "NO") << std::endl;



    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}


    delete client1;
    delete client2;
    delete client3;
}



void Tester::TChannel::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    Client *client1 = NULL;
    Client *client2 = NULL;
    Client *client3 = NULL;
    client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
    client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-14");
    client3 = new Client("Steve-HRV", "steve-harvy", "localhost", "debian-15");

    try
    {
        Channel channel("#global", "general conversations");
        std::cout << channel << std::endl;
    }
    catch(const IllegalArgumentException& e)
    {std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    delete client1;
    delete client2;
    delete client3;
}

