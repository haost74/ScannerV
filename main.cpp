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

template<typename... ArgTypes>
void set(expand_type& ex, ArgTypes... args){
  expand_type _ex {0, (std::cout << args, 0)...};
  ex = _ex;
}

template <typename T>
void func(T t) 
{
    std::cout << "n " << __PRETTY_FUNCTION__ << " :" << t << std::endl ;
}

template<typename T, typename... Args>
void func(T t, Args... args) // recursive variadic function
{
    std::cout << __PRETTY_FUNCTION__ << " :" << t <<std::endl ;

    func(args...) ;
}


struct dt{
    int num;
    std::string str;
};

int main()
{   

    //dt d = {4, "hello"};

    //std::cout << d.str << '\n';

    // return 0;
    requireDb rdb;
    std::vector<std::vector<vType>> vec;
    rdb.getData<person>("select * from actionaddress;", vec);
    //rdb.getData<person>("select * from parameter_end", vec);
    
     std::cout << vec[0].size() << '\n';

    auto tm = std::get_if<double>(&vec[0][0].var);
    if(tm != nullptr)
            std::cout << *tm << '\n';
   

// rdb.endIp();
// std::cout << rdb.endIp() << '\n';

// runConnected rc;
// rc.startAsync();
// rc.startAsync(63, 63, 63, 62);
// rc.startAsync(127, 127, 127, 126);
// rc.startAsync(190, 190, 190, 189);
    
    // std::string h{""};
    // while (h != "h")
    // {
    //     std::cin >> h;
    // }
    

    return 0;
}
