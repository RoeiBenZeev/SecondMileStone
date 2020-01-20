//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__SEARCHER_H_
#define SECONDMILESTONE__SEARCHER_H_

#include <queue>
#include "ISearcher.h"
#include "customPriorityQueue.h"
template<typename S,typename E>
class Searcher : public ISearcher<S,E> {

  protected:
    customPriorityQueue<E>* myPriorityQueue = new customPriorityQueue<E>();
    int evaluatedNodes;


  public:
    int getEvaluatedNodes() override {
        return this->evaluatedNodes;
    }

};

#endif //SECONDMILESTONE__SEARCHER_H_
