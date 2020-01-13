//
// Created by asaf on 12/01/2020.
//

#include <algorithm>
#include "StringReverser.h"

string StringReverser::solve(string problem) {
    string solution = problem;
    reverse(solution.begin(),solution.end());//todo: should I implement by myself?
    return solution;
}
