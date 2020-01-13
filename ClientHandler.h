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
    virtual void handleClient(string problem) = 0;
};

#endif //SECONDMILESTONE__CLIENTHANDLER_H_
