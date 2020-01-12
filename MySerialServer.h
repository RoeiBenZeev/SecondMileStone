//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__MYSERIALSERVER_H_
#define SECONDMILESTONE__MYSERIALSERVER_H_

#include "Server.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <list>
#include <fstream>
#include <functional>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <iostream>
#include <cstring>


class MySerialServer : server_side::Server {
  public:
    void open(int, ClientHandler*) override;
    void stop();
};

#endif //SECONDMILESTONE__MYSERIALSERVER_H_