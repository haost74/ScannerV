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

#include <stdarg.h>
#include <variant>

#include "connect.cpp"
#include "address.h"
#include "db/postgres.h"
#include "connectedIp/runConnected.h"

#include "db/require/requireDb.h"

struct foo
{
    int i{0};
    std::string str{"h"};
};


template<class T>
struct tmp
{
    T nm;
};



struct expand_type {
  template<typename... T>
  expand_type(T&&...) {}
};

template<typename... ArgTypes>
void print(ArgTypes... args)
{ 
  expand_type{ 0, (std::cout << args, 0)... };
}


struct person
{
    
    std::string addr;
};





int main()
{   
    requireDb rdb;
    
    std::vector<std::vector<vType>> vec;
    rdb.getData<person>("select * from actionaddress;", vec);
    //rdb.getData<person>("select * from parameter_end", vec);
    
    auto tm = 
    std::get_if<double>(&vec[5][1].var);
    if(tm != nullptr)
    std::cout << *tm << '\n';
   

// rdb.endIp();
// std::cout << rdb.endIp() << '\n';

// runConnected rc;
// rc.startAsync();
// rc.startAsync(63, 63, 63, 62);
// rc.startAsync(127, 127, 127, 126);
// rc.startAsync(190, 190, 190, 189);
    
    //  std::string h{""};
    // while (h != "h")
    // {
    //     std::cin >> h;
    // }
    

    return 0;
}
