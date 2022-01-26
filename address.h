#ifndef __ADDRESS_CPP__
#define __ADDRESS_CPP__

#include <string>
#include <vector>
#include <algorithm>


class address
{
private:
    /* data */
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = -1;
    const std::vector<int> shortList{10, 127, 192};
    void checkShort(int& d1);

public:
    address(/* args */);
    ~address();
    std::string getAddress();
    void setAddress(int d1, int d2, int d3, int d4);

};




#endif