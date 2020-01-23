//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__SOLVER_H_
#define SECONDMILESTONE__SOLVER_H_

#include <string>
template <typename P, typename S>
class Solver {
  public:
    virtual S solve(P problem) = 0;
    virtual Solver* clone() = 0;
    virtual ~Solver() = default;
    virtual std::string toString() = 0;

};

#endif //SECONDMILESTONE__SOLVER_H_
