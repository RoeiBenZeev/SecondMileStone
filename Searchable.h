//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__SEARCHABLE_H_
#define SECONDMILESTONE__SEARCHABLE_H_
#include "State.h"
#include <vector>
using namespace std;

template <typename E>
class Searchable {
  public:
    virtual State<E>* getInitialState() = 0;
    virtual bool isGoalState(State<E>*) = 0;
    virtual vector<State<E>*> getAllPossibleStates(State<E>*) = 0;
};

#endif //SECONDMILESTONE__SEARCHABLE_H_
