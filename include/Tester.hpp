#pragma once

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
        class TClientRepo
        {
            private:
                TClientRepo();
                TClientRepo(const TClientRepo&);
                TClientRepo& operator=(const TClientRepo&);
                ~TClientRepo();
            
            public:
                static void test(const std::string& title);
        };
        class TClientService
        {
            private:
                TClientService();
                TClientService(const TClientService&);
                TClientService& operator=(const TClientService&);
                ~TClientService();
            
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
};



