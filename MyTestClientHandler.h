//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__MYTESTCLIENTHANDLER_H_
#define SECONDMILESTONE__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <iostream>

using namespace std;


class MyTestClientHandler : public ClientHandler {
private:
    Solver<string, string> *solver;
    CacheManager<string, string> *cacheManager;
public:
    MyTestClientHandler(Solver<string, string> *s, CacheManager<string, string> *cm);
    void handleClient(string problem) override;

};

#endif //SECONDMILESTONE__MYTESTCLIENTHANDLER_H_
