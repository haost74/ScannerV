#ifndef __requireDb__CXX__
#define __requireDb__CXX__

#include <string>
#include <vector>
#include <algorithm>
#include <variant>

#include "../postgres.h"

struct vType
{
    std::variant< double, std::string > var;
};


class requireDb{
  private:
    postgres db;
    void connectDb();
    bool is_number(const std::string& s);
    std::string key{""};
    public:
    std::string endIp();
    requireDb();
    bool isConnect{false};

    template<class T>
    void getData(std::string sql, std::vector<std::vector<vType>> &dataList){
        connectDb();
       
        if(isConnect){
            auto res = db.require(sql);
            
            for(auto row : res){
                
                auto data = row[1].c_str();   
                auto sz = row.size(); 
                int i = 0;                
                std::vector<vType> tmpData;
                while (i < sz)
                {
                    try
                    {
                        auto ds = row[i];
                        vType vtmp ;

                      if(is_number(ds.c_str())){                          
                          vtmp.var  = ds.as<double>();
                        }
                        else
                        {
                            vtmp.var  = ds.as<std::string>();
                        }

                        tmpData.push_back(vtmp);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                    
                    
                    ++i;
                }

                dataList.push_back(tmpData);
            }
        }
        else{
            std::cout << 1024 + 50 << '\n';
        }
    }
};

#endif