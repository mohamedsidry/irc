#ifndef TESTER_HPP
#define TESTER_HPP

#include "test.hpp"

class Tester 
{
    public:
        class TClient
        {
            private:
                TClient();
                TClient(const TClient&);
                TClient& operator=(const TClient&);
                ~TClient();
            public:
                static void test(const std::string& title, const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& hostuser);
        };
        class TClientsRepo
        {
            private:
                TClientsRepo();
                TClientsRepo(const TClientsRepo&);
                TClientsRepo& operator=(const TClientsRepo&);
                ~TClientsRepo();
            
            public:
                static void test(const std::string& title);
        };
        class TClientsService
        {
            private:
                TClientsService();
                TClientsService(const TClientsService&);
                TClientsService& operator=(const TClientsService&);
                ~TClientsService();
            
            public:
                static void test(const std::string& title);
        };
        class TChannelMetaData
        {
            private:
                TChannelMetaData();
                TChannelMetaData(const TChannelMetaData&);
                TChannelMetaData& operator=(const TChannelMetaData&);
                ~TChannelMetaData();
            
            public:
                static void test(const std::string& title);
        };
        class TChannelMetaDataService
        {
            private:
                TChannelMetaDataService();
                TChannelMetaDataService(const TChannelMetaDataService&);
                TChannelMetaDataService& operator=(const TChannelMetaDataService&);
                ~TChannelMetaDataService();
            
            public:
                static void test(const std::string& title);
        };
        class TChannelMode
        {
            private:
                TChannelMode();
                TChannelMode(const TChannelMode&);
                TChannelMode& operator=(const TChannelMode&);
                ~TChannelMode();
            
            public:
                static void test(const std::string& title);
        };
        class TChannelModeService
        {
            private:
            TChannelModeService();
            TChannelModeService(const TChannelModeService&);
            TChannelModeService& operator=(const TChannelModeService&);
            ~TChannelModeService();
            
            public:
                static void test(const std::string& title);
        };
        class TSubscribersRepo
        {
            private:
            TSubscribersRepo();
            TSubscribersRepo(const TSubscribersRepo&);
            TSubscribersRepo& operator=(const TSubscribersRepo&);
            ~TSubscribersRepo();
            
            public:
            static void test(const std::string& title);
        };
        class TSubscribersService
        {
            private:
            TSubscribersService();
            TSubscribersService(const TSubscribersService&);
            TSubscribersService& operator=(const TSubscribersService&);
            ~TSubscribersService();
            
            public:
            static void test(const std::string& title);
        };
        class TModeratorsRepo
        {
            private:
            TModeratorsRepo();
            TModeratorsRepo(const TModeratorsRepo&);
            TModeratorsRepo& operator=(const TModeratorsRepo&);
            ~TModeratorsRepo();
            
            public:
            static void test(const std::string& title);
        };
        class TModeratorsService
        {
            private:
            TModeratorsService();
            TModeratorsService(const TModeratorsService&);
            TModeratorsService& operator=(const TModeratorsService&);
            ~TModeratorsService();
            
            public:
            static void test(const std::string& title);
        };
        class TChannel
        {
            private:
                TChannel();
                TChannel(const TChannel&);
                TChannel& operator=(const TChannel&);
                ~TChannel();
                
            public:
                    static void test(const std::string& title);
        };
};


#endif // TESTER_HPP

