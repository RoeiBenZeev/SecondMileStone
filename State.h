//
// Created by roei on 14/01/2020.
//

#ifndef SECONDMILESTONE__STATE_H_
#define SECONDMILESTONE__STATE_H_
template<typename E>
class State {
  private:
    E state;
    int totalCost;
    State<E>* cameFrom;
  public:
    E GetState() const;
    int getTotalCost() const;

    State<E> *getCameFrom() const;
    void SetTotalCost(int total_cost);
    void setCameFrom(State<E> *cameFrom);

    State(E state, int total_cost, State<E> *came_from);
    State(E state);
};

template<typename E>
State<E> *State<E>::getCameFrom() const {
    return cameFrom;
}

//thisCost is the cost of getting to this state from cameFrom State
template<typename E>
State<E>::State(E state, int thisCost, State<E> *came_from) : state(state), cameFrom(came_from) {
    totalCost = came_from->GetTotalCost() + thisCost;
}
template<typename E>
State<E>::State(E state):state(state) {
    totalCost = 0;
    cameFrom = nullptr;
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

#endif //SECONDMILESTONE__STATE_H_
