//
// Created by roei on 15/01/2020.
//

#ifndef SECONDMILESTONE__SOLVERADAPTER_H_
#define SECONDMILESTONE__SOLVERADAPTER_H_

#include "Solver.h"
#include "Searcher.h"
/*
 * This class is used as Object Adapter
 * */
template <typename P, typename S, typename E>
class SolverAdapter : public Solver<P,S> {
  private:
    Searcher<S,E> searcher;

  public:
    S solve(P problem) override {
        //implementation here
    }
};

#endif //SECONDMILESTONE__SOLVERADAPTER_H_
