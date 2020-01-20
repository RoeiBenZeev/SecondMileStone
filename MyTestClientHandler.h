//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__MYTESTCLIENTHANDLER_H_
#define SECONDMILESTONE__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "MatrixProblem.h"
#include <iostream>
#include<string.h>
#include <cstring>
#include <sys/socket.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;
extern int threadcounter;

class MyTestClientHandler : public ClientHandler {
  public:
    MyTestClientHandler(Solver<MatrixProblem*,string> *s, CacheManager<string, string> *cm);
    void handleClient(int) override;
    ClientHandler *clone() override;
    virtual ~MyTestClientHandler();
  private:
    Solver<MatrixProblem*, string> *solver;
    CacheManager<string, string> *cacheManager;

};

#endif //SECONDMILESTONE__MYTESTCLIENTHANDLER_H_
