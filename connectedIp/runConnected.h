#ifndef __RunConnected__CXX__
#define  __RunConnected__CXX__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

#include "../address.h"
#include "../connect.cpp"


struct data
{
   bool isRes;
   std::string addresStr;
   int port;
   double tymeRun;
};

class runConnected
{
private:
    data run(std::string address, int port);
public:
    void start(int d1 = 0, int d2 = 0, int d3 = 0, int d4 = -1);
    void startAsync(int d1 = 0, int d2 = 0, int d3 = 0, int d4 = -1);
    runConnected(/* args */);
    ~runConnected();
};




#endif