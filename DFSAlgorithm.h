//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__DFSALGORITHM_H_
#define SECONDMILESTONE__DFSALGORITHM_H_

#include "ISearcher.h"

template <typename E>
class DFSAlgorithm : public ISearcher<E> {

  private:
    int evaluatedNodes;
  public:
    string Search(Searchable<E> problem) override;
    int getEvaluatedNodes() override;
  public:
    DFSAlgorithm();
};

template<typename E>
DFSAlgorithm<E>::DFSAlgorithm() {

}

template<typename E>
string DFSAlgorithm<E>::Search(Searchable<E> problem) {

}
template<typename E>
int DFSAlgorithm<E>::getEvaluatedNodes() {

}

#endif //SECONDMILESTONE__DFSALGORITHM_H_
