#include "requireDb.h"

void requireDb::connectDb(){
    if(!isConnect){
        isConnect = static_cast<bool>(db.init("tkhhpiuo", 
                    "abul.db.elephantsql.com", 
                    key, 
                    "tkhhpiuo")); 
    }
}

std::string requireDb::endIp(){
    std::string addr{""};
    
    connectDb();

    if(isConnect)
    {
        auto res = db.require("select * from parameter_end where id = (select max(id) from parameter_end) limit 1;");

        for(auto row : res)
        {           
            addr = row[0].c_str();    
            std::cout << addr << '\n';  

                  
        }
    }

    return addr;
}

bool requireDb::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

requireDb::requireDb()
{
    key = db.GetKey("../key.txt");
}