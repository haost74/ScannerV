#include "runConnected.h"


data runConnected::run(std::string addressStr, int port){
     address add;
    auto str = add.getAddress();
    connectSocet cs;
    data d;
    d.addresStr = addressStr;
    d.port = port;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    bool isRes = cs.init(addressStr, port);
    //std::cout << isRes << '\n';
    d.isRes = isRes;

    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

     // std::cout << ms_int.count() << "ms\n";
     //std::cout << ms_double.count() << "ms\n";
     d.tymeRun = ms_double.count();
    return d;
}

void runConnected::startAsync(int d1, int d2, int d3, int d4)
{
   std::thread th (&runConnected::start, this, d1, d2, d3, d4);
   th.detach();
}

void runConnected::start(int d1, int d2, int d3, int d4)
{
    
   //std::thread th([d1, d2, d3, d4, r](){

        address add;
        add.setAddress(d1,d2,d3,d4);

        while (true)
        {
            auto addStr = add.getAddress();
            int port = 1;
            while (port <= 65535)
            {
                std::future<data> ret = std::async(std::launch::async, &runConnected::run, this, addStr, port);
                data d = ret.get();
                if(d.isRes)
                std::cout << d.isRes << " port = " << d.port << '\n';
                ++port;
            }

            std::cout << "end address " << addStr << '\n';
        }
    //});
    //th.detach();
}


runConnected::runConnected(/* args */)
{
}

runConnected::~runConnected()
{
}