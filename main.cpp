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

#include "connect.cpp"
#include "address.h"
#include "db/postgres.h"
#include "connectedIp/runConnected.h"




// struct data
// {
//    bool isRes;
//    std::string addresStr;
//    int port;
//    double tymeRun;
// };


// data run(std::string addressStr, int port){
//      address add;
//     auto str = add.getAddress();
//     connectSocet cs;
//     data d;
//     d.addresStr = addressStr;
//     d.port = port;

//     using std::chrono::high_resolution_clock;
//     using std::chrono::duration_cast;
//     using std::chrono::duration;
//     using std::chrono::milliseconds;

//     auto t1 = high_resolution_clock::now();

//     bool isRes = cs.init(addressStr, port);
//     //std::cout << isRes << '\n';
//     d.isRes = isRes;

//     auto t2 = high_resolution_clock::now();

//     /* Getting number of milliseconds as an integer. */
//     auto ms_int = duration_cast<milliseconds>(t2 - t1);

//     /* Getting number of milliseconds as a double. */
//     duration<double, std::milli> ms_double = t2 - t1;

//     // std::cout << ms_int.count() << "ms\n";
//     // std::cout << ms_double.count() << "ms\n";
//      d.tymeRun = ms_double.count();
//     return d;
// }

// void start(int d1 = 0, int d2 = 0, int d3 = 0, int d4 = -1)
// {
//    std::thread th([d1, d2, d3, d4](){

//         address add;
//         add.setAddress(d1,d2,d3,d4);
//         while (true)
//         {
//             auto addStr = add.getAddress();
//             int port = 1;
//             while (port <= 65535)
//             {
//                 std::future<data> ret = std::async(&run, addStr, port);
//                 data d = ret.get();
//                 if(d.isRes)
//                 std::cout << d.isRes << " port = " << d.port << '\n';
//                 ++port;
//             }

//             std::cout << "end address " << addStr << '\n';
//         }
//     });
//     th.detach();
// }

int main()
{


postgres db;

auto key = db.GetKey("../key.txt");
    bool isConnect = static_cast<bool>(db.init("tkhhpiuo", "abul.db.elephantsql.com", 
    key, "tkhhpiuo"));   


runConnected rc;
rc.startAsync();
rc.startAsync(63, 63, 63, 62);
rc.startAsync(127, 127, 127, 126);
rc.startAsync(190, 190, 190, 189);
    
     std::string h{""};
    while (h != "h")
    {
        std::cin >> h;
    }
    

    return 0;
}
