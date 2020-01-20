//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__SEARCHSOLVERADAPTER_H_
#define SECONDMILESTONE__SEARCHSOLVERADAPTER_H_
#include "Solver.h"
#include "MatrixProblem.h"
#include "ISearcher.h"
#include <string>

using namespace std;
template <typename P, typename S>
class SearchSolverAdapter : public Solver<P,S> {
  private:
    ISearcher<S,Vertex*>* searcher;
  public:
    //solve function call solver inner object to run his solve method.
    S solve(P problem) override {

        return searcher->Search(problem);
    }
    //constructor
    SearchSolverAdapter(ISearcher<S,Vertex*>* searcher) : searcher(searcher) {}
    Solver<P, S> *clone() override {
        ISearcher<S,Vertex*>* tempSearcher = searcher->clone();
        return new SearchSolverAdapter(tempSearcher);
    }

};

#endif //SECONDMILESTONE__SEARCHSOLVERADAPTER_H_
