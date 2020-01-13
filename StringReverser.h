//
// Created by asaf on 12/01/2020.
//

#ifndef SECONDMILESTONE_STRINGREVERSER_H
#define SECONDMILESTONE_STRINGREVERSER_H


#include "Solver.h"
#include <iostream>
using namespace std;

class StringReverser : public Solver<string, string> {
public:
    string solve(string problem) override;
};


#endif //SECONDMILESTONE_STRINGREVERSER_H
