#ifndef __CONNECT__CXX__
#define __CONNECT__CXX__

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


struct connectSocet{

  bool init(std::string addressStr, int port)
    {
        int sockfd = 0, n = 0;
        struct sockaddr_in serv_addr;

        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            //printf("\n Error : Could not create socket \n");
            return false;
        } 

        memset(&serv_addr, '0', sizeof(serv_addr)); 

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);

        if(inet_pton(AF_INET, addressStr.c_str(), &serv_addr.sin_addr)<=0)
        {
            //printf("\n inet_pton error occured\n");
            return false;
        }

        if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
        //printf("\n Error : Connect Failed \n");
        
        return false;
        }
        else
        {
            return true;
        }
    }
};


#endif