//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__STATE_H_
#define SECONDMILESTONE__STATE_H_
#include <limits>
template<typename E>
class State {
  private:
    E state;
  public:
    int GetStateCost() const;
  private:
    int totalCost;
    int stateCost;
    State<E>* cameFrom;
  public:
    E GetState() const;
    int getTotalCost() const;

    State<E> *getCameFrom() const;
    void SetTotalCost(int total_cost);
    void setCameFrom(State<E> *cameFrom);

    State(E state, int state_cost);
};

template<typename E>
State<E> *State<E>::getCameFrom() const {
    return cameFrom;
}

template<typename E>
E State<E>::GetState() const {
    return state;
}
template<typename E>
void State<E>::SetTotalCost(int total_cost) {
    totalCost = total_cost;
}

template<typename E>
void State<E>::setCameFrom(State<E> *cameFrom) {
    State::cameFrom = cameFrom;
}

template<typename E>
int State<E>::getTotalCost() const {
    return totalCost;
}
template<typename E>
State<E>::State(E state, int state_cost) {
    this->stateCost = state_cost;
    this->state = state;
    //each new state cost initial to infinity to be able to search properly.
    this->totalCost = std::numeric_limits<int>::max();
}
template<typename E>
int State<E>::GetStateCost() const {
    return stateCost;
}

#endif //SECONDMILESTONE__STATE_H_
