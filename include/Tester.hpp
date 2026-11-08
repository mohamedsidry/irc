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
        class TChannelRepo
        {
            private:
                TChannelRepo();
                TChannelRepo(const TChannelRepo&);
                TChannelRepo& operator=(const TChannelRepo&);
                ~TChannelRepo();
            
            public:
                static void test(const std::string& title);
        };
        class TChannelService
        {
            private:
                TChannelService();
                TChannelService(const TChannelService&);
                TChannelService& operator=(const TChannelService&);
                ~TChannelService();
            
            public:
                static void test(const std::string& title);
        };

};



