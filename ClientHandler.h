//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__CLIENTHANDLER_H_
#define SECONDMILESTONE__CLIENTHANDLER_H_

#include "Solver.h"
#include <iostream>

using namespace std;

class ClientHandler {
  public:
    virtual void handleClient(int) = 0;
    virtual ClientHandler* clone() = 0;
    virtual ~ClientHandler() {};
};

#endif //SECONDMILESTONE__CLIENTHANDLER_H_
