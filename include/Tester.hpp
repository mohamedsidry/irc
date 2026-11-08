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
        class TChannelData
        {
            private:
                TChannelData();
                TChannelData(const TChannelData&);
                TChannelData& operator=(const TChannelData&);
                ~TChannelData();
            
            public:
                static void test(const std::string& title);
        };
        class TChannelDataService
        {
            private:
                TChannelDataService();
                TChannelDataService(const TChannelDataService&);
                TChannelDataService& operator=(const TChannelDataService&);
                ~TChannelDataService();
            
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
        class TSubscriptionRepo
        {
            private:
                TSubscriptionRepo();
                TSubscriptionRepo(const TSubscriptionRepo&);
                TSubscriptionRepo& operator=(const TSubscriptionRepo&);
                ~TSubscriptionRepo();
            
            public:
                static void test(const std::string& title);
        };
        class TSubscriptionService
        {
            private:
                TSubscriptionService();
                TSubscriptionService(const TSubscriptionService&);
                TSubscriptionService& operator=(const TSubscriptionService&);
                ~TSubscriptionService();
            
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

};



