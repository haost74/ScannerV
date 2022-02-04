#include "utility.h"


void utility::splitStr(string s, string delimiter,
              vector<string> &res){
    
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        //std::cout << token << std::endl;
        res.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    //std::cout << s << std::endl;
    res.push_back(s);

}