//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__SEARCHSOLVERADAPTER_H_
#define SECONDMILESTONE__SEARCHSOLVERADAPTER_H_
#include "Solver.h"
#include "MatrixProblem.h"
#include <string>

using namespace std;
template <typename P, typename S>
class SearchSolverAdapter : public Solver<P,S> {
  private:
    Solver<P,S>* solver;
    P* problem;
  public:
    //solve function call solver inner object to run his solve method.
    S solve(P problem) override {
        solver->solve(problem);
    }
    //constructor
    SearchSolverAdapter(const Solver<P,S> *solver, P* problem) : solver(solver), problem(problem) {}
};

#endif //SECONDMILESTONE__SEARCHSOLVERADAPTER_H_
