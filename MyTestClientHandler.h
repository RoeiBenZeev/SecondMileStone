//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__MYTESTCLIENTHANDLER_H_
#define SECONDMILESTONE__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
class MyTestClientHandler : ClientHandler {
  public:
    Solver solver;
    CacheManager cm;
};

#endif //SECONDMILESTONE__MYTESTCLIENTHANDLER_H_
