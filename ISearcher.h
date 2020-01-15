//
// Created by roei on 15/01/2020.
//

#ifndef SECONDMILESTONE__ISEARCHER_H_
#define SECONDMILESTONE__ISEARCHER_H_

#include <string>
#include <iostream>
#include "Searchable.h"
template<typename E>
class ISearcher {
  public:
    virtual string Search(Searchable<E> problem) = 0;
    virtual int getEvaluatedNodes() = 0;
};


#endif //SECONDMILESTONE__ISEARCHER_H_


