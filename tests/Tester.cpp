#include "Tester.hpp"



void Tester::TClient::test(const std::string& title, const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    try
    {
        AUser *client = new Client(nickname, username, hostname, hostuser);
        std::cout << *client ;
        delete client;
    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }
}

void Tester::TClientsRepo::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    try
    {
        ClientsRepository repository;
        AUser *client1 = IUserFactory::createUser("Client", "Adam-AK47", "adambrands", "localhost", "debian-13");
        std::cout << *client1 << std::endl;
        AUser *client2 = IUserFactory::createUser("Client", "Bob-1337", "bobmarlin", "localhost", "debian-12");
        std::cout << *client2 << std::endl;

        std::cout << "Number of clients : " << repository.size() << std::endl;
        repository.add(client1);
        std::cout << "Number of clients after adding 1st client : " << repository.size() << std::endl;
        repository.add(client2);
        std::cout << "Number of clients after adding 2nd client : " << repository.size() << std::endl;
        std::cout << "clients repo has " << client1->getNickName() << (repository.has(client1->getNickName())  ? " YES" : " NO")<< std::endl;
        std::cout << "clients repo has " << client2->getNickName() << (repository.has(client2->getNickName())  ? " YES" : " NO")<< std::endl;
        std::cout << "clients repo has " << "UNKNOWN" << (repository.has("UNKNOWN")  ? " YES" : " NO")<< std::endl;

        
        std::cout << "remove client that exist :" << std::endl;
        repository.remove(client1->getNickName());
        std::cout << "Number of clients after remove 1st client : " << repository.size() << std::endl;
        std::cout << "remove client that is not exist :" << std::endl;
        repository.remove("Bob-42");
        std::cout << "Number of clients after adding random client : " << repository.size() << std::endl;
        repository.rename(client2->getNickName(), "Hannibal");
        std::cout << *dynamic_cast<AUser*>(client2) << std::endl;


    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
}

void Tester::TClientsService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ClientsRepository repository;
    ClientsService service(repository);

    try
    {
        service.addClient("Adam-AK1", "adambrands", "localhost", "debian-13");
        std::cout << "Adam-AK1" << "added succuessfuly" << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.addClient("Adam-AK1", "adambrands", "localhost", "debian-13");
        std::cout << "Adam-AK1" << "added succuessfuly" << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
    try
    {
        service.addClient("Adam-AK10", "adambrands", "localhost", "debian-13");
        std::cout << "Adam-AK10" << "added succuessfuly" << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    

    try
    {
        service.addClient("Adam-AK100", "adambrands", "localhost", "debian-13");
        std::cout << "Adam-AK100" << "added succuessfuly" << std::endl;
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << "NUMBER OF CLIENTS : " << repository.size() << std::endl;

    std::cout << "Has Adam-AK1 : " << (service.hasClient("Adam-AK1") ? "YES" : "NO") << std::endl;
    std::cout << "Has Adam-AK10 : " << (service.hasClient("Adam-AK10") ? "YES" : "NO") << std::endl;
    std::cout << "Has Adam-AK100 : " << (service.hasClient("Adam-AK100") ? "YES" : "NO") << std::endl;

    try
    {
        service.renameClient("Adam-AK1", "Adam-AK99");
        service.renameClient("Adam-AK10", "Adam-AK1099");
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << "Has Adam-AK1 : " << (service.hasClient("Adam-AK1") ? "YES" : "NO") << std::endl;
    std::cout << "Has Adam-AK99 : " << (service.hasClient("Adam-AK99") ? "YES" : "NO") << std::endl;
    std::cout << "Has Adam-AK10 : " << (service.hasClient("Adam-AK10") ? "YES" : "NO") << std::endl;
    std::cout << "Has Adam-AK1099 : " << (service.hasClient("Adam-AK1099") ? "YES" : "NO") << std::endl;
    std::cout << "NUMBER OF CLIENTS : " << repository.size() << std::endl;
    try
    {
        service.removeClient("Adam-AK10");
        service.removeClient("Adam-AK99");
        service.removeClient("Adam-AK111");
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "NUMBER OF CLIENTS : " << repository.size() << std::endl;
}

void Tester::TSubscribersRepo::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    AUser *subscriber1 = new Subscriber("Adam-AK47", "adambrands", "localhost", "debian-13");
    AUser *subscriber2 = new Subscriber("Bob-1337", "bobmarlin", "localhost", "debian-12");
    try
    {
        SubscribersRepository repository;
        std::cout << *subscriber1 << std::endl;
        std::cout << *subscriber2 << std::endl;

        std::cout << "Number of subscribers : " << repository.size() << std::endl;
        repository.add(subscriber1);
        std::cout << "Number of subscribers after adding 1st subscriber : " << repository.size() << std::endl;
        repository.add(subscriber2);
        std::cout << "Number of subscribers after adding 2nd subscriber : " << repository.size() << std::endl;
        std::cout << "subscribers repo has " << subscriber1->getNickName() << (repository.has(subscriber1->getNickName())  ? " YES" : " NO")<< std::endl;
        std::cout << "subscribers repo has " << subscriber2->getNickName() << (repository.has(subscriber2->getNickName())  ? " YES" : " NO")<< std::endl;
        std::cout << "subscribers repo has " << "UNKNOWN" << (repository.has("UNKNOWN")  ? " YES" : " NO")<< std::endl;

        
        std::cout << "remove subscriber1 that exist :" << std::endl;
        repository.remove(subscriber1->getNickName());
        std::cout << "Number of subscribers after remove 1st subscriber : " << repository.size() << std::endl;
        std::cout << "remove subscriber that is not exist :" << std::endl;
        repository.remove("Bob-42");
        std::cout << "Number of subscribers after adding random subscriber : " << repository.size() << std::endl;
        repository.rename(subscriber2->getNickName(), "Subscriber");
        std::cout << *dynamic_cast<AUser*>(subscriber2) << std::endl;


    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
    delete subscriber1;
    delete subscriber2;
}

void Tester::TSubscribersService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    SubscribersRepository repository;
    SubscribersService service(repository);
    Subscriber *subscriber1 = new Subscriber("Adam-AK1", "adambrands", "localhost", "debian-13");
    Subscriber *subscriber2 = new Subscriber("Adam-AK2", "adambrands", "localhost", "debian-13");
    Subscriber *subscriber3 = new Subscriber("Adam-AK3", "adambrands", "localhost", "debian-13");
    Subscriber *subscriber4 = new Subscriber("Adam-AK4", "adambrands", "localhost", "debian-13");
    try
    {
        service.addSubscriber(subscriber1);
        service.addSubscriber(subscriber2);
        service.addSubscriber(subscriber3);
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << "NUMBER OF SUBSCRIBERS : " << repository.size() << std::endl;

    try
    {
        service.addSubscriber(subscriber1);
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.renameSubscriber(subscriber1->getNickName(), "NewName");
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << subscriber1->getNickName() << " IS Subscribing : " << (service.hasSubscriber(subscriber1->getNickName()) ? "YES" : "NO") << std::endl;
    std::cout << subscriber2->getNickName() << " IS Subscribing : " << (service.hasSubscriber(subscriber2->getNickName()) ? "YES" : "NO") << std::endl;
    std::cout << subscriber3->getNickName() << " IS Subscribing : " << (service.hasSubscriber(subscriber3->getNickName()) ? "YES" : "NO") << std::endl;
    std::cout << subscriber4->getNickName() << " IS Subscribing : " << (service.hasSubscriber(subscriber4->getNickName()) ? "YES" : "NO") << std::endl;
    try
    {
        service.removeSubscriber(subscriber1->getNickName());
        service.removeSubscriber(subscriber2->getNickName());
        service.removeSubscriber(subscriber3->getNickName());
        service.removeSubscriber(subscriber4->getNickName());
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "NUMBER OF SUBSCRIBERS : " << repository.size() << std::endl;

    delete subscriber1;
    delete subscriber2;
    delete subscriber3;
    delete subscriber4;
}


void Tester::TModeratorsRepo::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    Moderator *moderator1 = new Moderator("Adam-AK47", "adambrands", "localhost", "debian-13");
    Moderator *moderator2 = new Moderator("Bob-1337", "bobmarlin", "localhost", "debian-12");
    try
    {
        ModeratorsRepository repository;
        std::cout << *dynamic_cast<AUser*>(moderator1) << std::endl;
        std::cout << *dynamic_cast<AUser*>(moderator2) << std::endl;

        std::cout << "Number of moderators : " << repository.size() << std::endl;
        repository.add(moderator1);
        std::cout << "Number of moderators after adding 1st moderator : " << repository.size() << std::endl;
        repository.add(moderator2);
        std::cout << "Number of moderators after adding 2nd moderator : " << repository.size() << std::endl;
        std::cout << "moderators repo has " << moderator1->getNickName() << (repository.has(moderator1->getNickName())  ? " YES" : " NO")<< std::endl;
        std::cout << "moderators repo has " << moderator2->getNickName() << (repository.has(moderator2->getNickName())  ? " YES" : " NO")<< std::endl;
        std::cout << "moderators repo has " << "UNKNOWN" << (repository.has("UNKNOWN")  ? " YES" : " NO")<< std::endl;

        
        std::cout << "remove moderator that exist :" << std::endl;
        repository.remove(moderator1->getNickName());
        std::cout << "Number of moderators after remove 1st moderator : " << repository.size() << std::endl;
        std::cout << "remove moderator that is not exist :" << std::endl;
        repository.remove("Bob-42");
        std::cout << "Number of moderators after adding random moderator : " << repository.size() << std::endl;
        repository.rename(moderator2->getNickName(), "Moderator");
        std::cout << *dynamic_cast<AUser*>(moderator2) << std::endl;
        
    } catch(const IllegalArgumentException& e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; 
    }
    delete moderator1;
    delete moderator2;
}

void Tester::TModeratorsService::test(const std::string& title)
{
    std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
    ModeratorsRepository repository;
    ModeratorsService service(repository);
    Moderator *moderator1 = new Moderator("Adam-AK1", "adambrands", "localhost", "debian-13");
    Moderator *moderator2 = new Moderator("Adam-AK2", "adambrands", "localhost", "debian-13");
    Moderator *moderator3 = new Moderator("Adam-AK3", "adambrands", "localhost", "debian-13");
    Moderator *moderator4 = new Moderator("Adam-AK4", "adambrands", "localhost", "debian-13");
    try
    {
        service.addModerator(moderator1);
        service.addModerator(moderator2);
        service.addModerator(moderator3);
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << "NUMBER OF MODERATORS : " << repository.size() << std::endl;

    try
    {
        service.addModerator(moderator2);
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    try
    {
        service.renameModerator(moderator1->getNickName(), "NewName");
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

    std::cout << moderator1->getNickName() << " IS Moderator : " << (service.hasModerator(moderator1->getNickName()) ? "YES" : "NO") << std::endl;
    std::cout << moderator2->getNickName() << " IS Moderator : " << (service.hasModerator(moderator2->getNickName()) ? "YES" : "NO") << std::endl;
    std::cout << moderator3->getNickName() << " IS Moderator : " << (service.hasModerator(moderator3->getNickName()) ? "YES" : "NO") << std::endl;
    std::cout << moderator4->getNickName() << " IS Moderator : " << (service.hasModerator(moderator4->getNickName()) ? "YES" : "NO") << std::endl;
    try
    {
        service.removeModerator(moderator1->getNickName());
        service.removeModerator(moderator2->getNickName());
        service.removeModerator(moderator3->getNickName());
        service.removeModerator(moderator4->getNickName());
    }
    catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    std::cout << "NUMBER OF MODERATORS : " << repository.size() << std::endl;

    delete moderator1;
    delete moderator2;
    delete moderator3;
    delete moderator4;
}




// void Tester::TChannel::test(const std::string& title)
// {
//     std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
//     Client *client1 = NULL;
//     Client *client2 = NULL;
//     Client *client3 = NULL;
//     client1 = new Client("Adam-AK47", "adambrands", "localhost", "debian-13");
//     client2 = new Client("Bob-1337", "bobmarlin", "localhost", "debian-14");
//     client3 = new Client("Steve-HRV", "steve-harvy", "localhost", "debian-15");

//     try
//     {
//         Channel channel("#global", "general conversations");
//         std::cout << channel << std::endl;
//     }
//     catch(const IllegalArgumentException& e)
//     {std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
//     delete client1;
//     delete client2;
//     delete client3;
// }

// void Tester::TChannelMetaData::test(const std::string& title)
// {
//     std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
//     ChannelMetaData data("Denzel Washinton", "Equalizer 1", "ifyouprayforraindealwithmud", 1024);
//     std::cout << data;

// }


// void Tester::TChannelMetaDataService::test(const std::string& title)
// {
//     std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
//     ChannelMetaData vdata("#General", "this channel is for free speech...", "BE-free-4-ever", 256);
//     ChannelMetaData fdata("Broken--", "this is channel with broken name ...", "brookkeeen", 256);
//     try
//     {
//         ChannelMetaDataService vv(vdata);
//         std::cout << "Channel Name : " << vv->getChannelName() << std::endl;
//         std::cout << "Channel Topic : " << vv->getChannelTopic() << std::endl;
//         std::cout << "Channel Key : " << vv->getChannelKey() << std::endl;
//         std::cout << "Channel Limit : " << vv->getChannelLimit() << std::endl;

//     }
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

//     try
//     {
//         ChannelMetaDataService ff(fdata);
//     }
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

// }



// void Tester::TChannelMode::test(const std::string& title)
// {
//     std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
//     ChannelMode mode("t");
//     std::cout << "ChannelMode flags : " << mode->getFlags() << std::endl;
//     mode.addFlag('i');
//     mode.addFlag('t');
//     mode.addFlag('k');
//     mode.addFlag('o');
//     mode.addFlag('l');
//     mode.addFlag('l');
//     mode.addFlag('l');
//     std::cout << "ChannelMode flags : " << mode->getFlags() << std::endl;
//     mode.removeFlag('l');
//     mode.removeFlag('o');
//     mode.removeFlag('k');
//     mode.removeFlag('t');
//     std::cout << "ChannelMode flags : " << mode->getFlags() << std::endl;
//     std::cout << "has flag {i} : " << (mode.hasFlag('i') ? "YES" : "NO") << std::endl;
// }


// void Tester::TChannelModeService::test(const std::string& title)
// {
//     std::cout << "\033[1;33m" << "TEST : " << title << "\033[0m"<< std::endl;
//     ChannelMode mode("t");
//     ChannelModeService service(mode);
//     /**
//     ∗ MODE - Change the channel’s mode:
//     · i: Set/remove Invite-only channel
//     · t: Set/remove the restrictions of the TOPIC command to channel operators
//     · k: Set/remove the channel key (password)
//     · o: Give/take channel operator privilege
//     · l: Set/remove the user limit to channel*/

//     std::cout << "Default channel mode : " << service->getChannelModes() << std::endl;
//     try{service.addMode('i');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

//     try{service.addMode('j');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     try{service.addMode('k');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

//     try{service.addMode('l');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     try{service.addMode('m');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     try{service.addMode('o');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     std::cout << "channel mode +i +j +k +l +m +o  : " << service->getChannelModes() << std::endl;
    
//     try{service.removeMode('i');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

//     try{service.removeMode('j');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     try{service.removeMode('k');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

//     try{service.removeMode('l');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     try{service.removeMode('m');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
    
//     try{service.removeMode('o');}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

//     std::cout << "channel mode  -j -k -l -m -o  : " << service->getChannelModes() << std::endl;
    
//     try{service.updateChannelMode("+iklot");}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
//     std::cout << "channel mode  +iklot  : " << service->getChannelModes() << std::endl;

//     try{service.updateChannelMode("-iklot");}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
//     std::cout << "channel mode  -iklot  : " << service->getChannelModes() << std::endl;

//     try{service.updateChannelMode("+iklot");}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
//     std::cout << "channel mode  +iklot  : " << service->getChannelModes() << std::endl;

//     try{service.updateChannelMode("+i-kl+ot");}
//     catch(const IllegalArgumentException& e){std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}
//     std::cout << "channel mode  +i-kl+ot  : " << service->getChannelModes() << std::endl;
//     std::cout << "channel mode  has i  : " << (service.hasMode('i') ? "YES" : "NO") << std::endl;

// }

