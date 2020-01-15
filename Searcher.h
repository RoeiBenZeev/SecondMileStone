//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__SEARCHER_H_
#define SECONDMILESTONE__SEARCHER_H_

#include <queue>
#include "ISearcher.h"
template <typename E>
class Searcher : public ISearcher<E> {

  protected:
    std::priority_queue<State<E>> q;
    int evaluatedNodes;

  public:
    virtual int getEvaluatedNodes() = 0; //todo: check abstract

};

#endif //SECONDMILESTONE__SEARCHER_H_
